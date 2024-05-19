fn main() {
    let text: String = String::from("eu trabalho no mercado");
    let pattern: String = String::from("no");
    println!("Find sub-string text:\"{text}\" pattern:\"{pattern}\"");
    println!("{}", substr(text, pattern));
}

fn substr(text: String, pattern: String) -> String  {
    let M: usize = text.len();
    let N: usize = pattern.len();
    
    for i in 0..M {
        println!("{i}");
    }

    for j in 0..N {
        println!("{j}");
    }
    
    String::from("pattern index")
}
