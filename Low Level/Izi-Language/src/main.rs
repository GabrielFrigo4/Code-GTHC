#![allow(non_snake_case)]

use std::{borrow::Borrow, collections::HashMap};

struct IziInstruction {

}

struct IziCodeNode {
    global_vars: HashMap<&'static str, IziVar>,
    next: Option<Box<IziCodeNode>>,
    instruction: IziInstruction,
}

impl IziCodeNode {
    fn execute(&self) -> Option<Box<IziCodeNode>> {
        self.instruction.execute();
    }
}

struct IziVar {
    value: i32,
}

fn main() {
    let mut map_var:HashMap<&str, IziVar> = HashMap::new();
    map_var.insert("var_numb", IziVar {value: 0});
    
    let last_code_node: IziCodeNode = IziCodeNode {
        global_vars: map_var,
        next: None,
        instruction: IziInstruction {},
    };
}
