fn main() {

    //let mut N = 5;
    //let xs: [i64; 5] = [1, 2, 3, 4, 5];

  //  float data[4][4];

//    println!("first element of the array: {0} {1}", xs[0], xs.len());

  let state : [[f32; 4]; 4] = [[1.0, 0.0, 0.0, 0.0],
                               [0.0, 1.0, 0.0, 0.0],
                               [0.0, 0.0, 1.0, 0.0],
                               [0.0, 0.0, 0.0, 1.0]];

  for i in 0..4 {
    for j in 0..4 {
      state[i][j] = 345.4;//i*10+j;
    }
  }

  println!("sf {}", state[1][1]);

}
