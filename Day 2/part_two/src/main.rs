fn main() {
    println!("Hello, world!");
    let path = std::env::args().nth(1).expect("No path to file given!");
    let content = std::fs::read_to_string(path).expect("Could not read file.");

    let mut depth = 0;
    let mut aim = 0;
    let mut horizontal = 0;

    for line in content.lines() {
        let data: Vec<&str> = line.split_whitespace().collect();
        let travel: i32 = data[1].parse().unwrap();
        match data[0] {
            "forward" =>  {
                horizontal += travel;
                depth += aim * travel;
            },
            "up" => aim -= travel,
            "down" => aim += travel,
            _ => {}
        }
    }

    println!("The output for part one is: {}", depth * horizontal);
}
