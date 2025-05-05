use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let input: Vec<u8> = input.trim().bytes().collect();
    
    println!("{}", input[0]);
}