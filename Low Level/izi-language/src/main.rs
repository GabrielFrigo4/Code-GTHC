use std::{collections::HashMap};

pub struct IziVar {
    value: i32,
}

impl IziVar {
    pub fn Copy(&self) -> Self {
        IziVar { value: self.value }
    }
}

pub enum IziCommand {
    New{ name: String },
    Del{ name: String },
    Inc{ name: String },
    Dec{ name: String },
    MovInt{ set: String, get: i32 },
    MovStr{ set: String, get: String },
    Echo{ name: String },
    Jmp{ pos: usize },
}

fn show_hashmap(map_var: &HashMap<String, IziVar>) {
    for (key, value) in map_var.into_iter() {
        println!("{} = {}", key, value.value);
    }    
}

fn main() {
    let mut map_var:HashMap<String, IziVar> = HashMap::new();
    let mut com: Vec<IziCommand> = Vec::new();
    com.push(IziCommand::New{ name: "new_var".to_owned() });
    com.push(IziCommand::Echo{ name: "new_var".to_owned() });
    com.push(IziCommand::Inc{ name: "new_var".to_owned() });
    com.push(IziCommand::Echo{ name: "new_var".to_owned() });
    com.push(IziCommand::Del{ name: "new_var".to_owned() });

    com.push(IziCommand::New{ name: "loop".to_owned() });
    com.push(IziCommand::Echo{ name: "loop".to_owned() });
    com.push(IziCommand::Inc{ name: "loop".to_owned() });
    com.push(IziCommand::Jmp{ pos: 6});
    
    let mut reg_pos: usize = 0;
    while reg_pos < com.len() {
        match &com[reg_pos] {
            IziCommand::New { name } => {
                map_var.insert(name.to_owned(), IziVar {value: 0});                
            }
            IziCommand::Del { name } => {
                map_var.remove(name);
            }
            IziCommand::Inc{ name } => {
                map_var.get_mut(name).unwrap().value += 1;
            }
            IziCommand::Dec{ name } => {
                map_var.get_mut(name).unwrap().value -= 1;
            }
            IziCommand::MovInt{ set, get } => {
                map_var.get_mut(set).unwrap().value = *get;
            }
            IziCommand::MovStr{ set, get } => {
                map_var.get_mut(set).unwrap().value = map_var[get].value;
            }
            IziCommand::Echo{ name } => {
                println!("{} = {}", name, map_var[name].value);
            }
            IziCommand::Jmp{ pos } => {
                reg_pos = *pos;
                continue;
            }
        }
        reg_pos += 1;
    }
    
    show_hashmap(&map_var);
}
