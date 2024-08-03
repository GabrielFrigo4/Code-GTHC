use std::fs::File;
use std::hash::{DefaultHasher, Hash, Hasher};
use std::io;
use std::io::prelude::*;
use std::io::BufReader;
use std::path::Path;

fn calculate_hash<T: Hash>(t: &T) -> u64 {
    let mut s = DefaultHasher::new();
    t.hash(&mut s);
    s.finish()
}

fn main() -> std::io::Result<()> {
    let stdin = io::stdin();
    let mut stdout = io::stdout();
    stdout.flush()?;

    println!("username: ");
    let mut username = String::new();
    stdin.read_line(&mut username)?;
    username = username.replace("\n", "");

    println!("password: ");
    let mut password = String::new();
    stdin.read_line(&mut password)?;
    password = password.replace("\n", "");
    password.push_str(":\"to_hash(1234567890!@#$%¨&*)\"");
    let hash_password = calculate_hash(&password);

    let mut filename = String::new();
    filename.push_str(&username);
    filename.push_str(":");
    filename.push_str(&hash_password.to_string());
    let exist = Path::new(&filename).is_file();
    let mut content = String::new();
    if exist {
        let file = File::open(&filename)?;
        let mut buf_reader = BufReader::new(file);
        buf_reader.read_to_string(&mut content)?;
    }
    println!("File: \"{}\"", &filename);
    println!("Data: \"{}\"", &content);

    println!("datafile: ");
    let mut datafile = String::new();
    stdin.read_line(&mut datafile)?;

    let mut file = File::create(&filename)?;
    file.write_all(datafile.as_bytes())?;
    Ok(())
}
