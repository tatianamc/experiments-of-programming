fn main() {
    let mut x = vec!["Hello", "world"];

    let y = x[0].clone();
    
    x.push("foo");
    
    println!("sdf {} {}", x[2], y);
}
