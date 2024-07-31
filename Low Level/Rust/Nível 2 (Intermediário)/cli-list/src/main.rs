use std::fs::File;
use std::io;
use std::io::prelude::*;
use std::io::BufReader;
use std::path::Path;

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

    let mut filename = String::new();
    filename.push_str(&username);
    filename.push_str(&password);
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
    datafile = datafile.replace("\n", "");

    let mut file = File::create(&filename)?;
    file.write_all(datafile.as_bytes())?;
    Ok(())
}
