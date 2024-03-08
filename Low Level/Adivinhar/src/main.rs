#![allow(non_snake_case)]

//https://doc.rust-lang.org/stable/book/ch02-00-guessing-game-tutorial.html/
use std::io;

fn main() {
    println!("Guess the number!");

    println!("Please input your guess.");

    let mut guess = String::new();

    io::stdin()
        .read_line(&mut guess)
        .expect("Failed to read line");

    println!("You guessed: {guess}");
}
