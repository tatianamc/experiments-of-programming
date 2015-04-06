fn main() {
    println!("!Hello, world!");
    
    let mut v = vec![];
    v.push("Hello");

    let x = v[0].clone();

    v.push("world");
    println!("{}", x);
    
    let vec = vec![1, 2, 3];

    for x in &vec {
        println!("{}", x);
    }
}
