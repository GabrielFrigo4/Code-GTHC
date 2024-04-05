#![allow(non_snake_case)]

use std::{collections::HashMap};
use core::ptr::NonNull;

pub struct IziVar {
    value: i32,
}

pub struct IziCommand {
    value: i32,
}

impl IziCommand {
    pub fn clone(&self) -> IziCommand {
	IziCommand {
	    value: self.value,
	}
    }
}

pub struct LinkedList<T> {
    pub value: Option<T>,
    pub next: Option<NonNull<LinkedList<T>>>,
}

impl LinkedList<IziCommand> {
    pub fn new() -> LinkedList<IziCommand>{
        LinkedList {
            value: None,
            next: None,
        }
    }

    pub fn push_left(&mut self, x: IziCommand) {
	let node = Box::new(LinkedList::<IziCommand> {
            next: None,
            value: Some(x)
	});

	if self.next.is_none() {
            let pter: NonNull<LinkedList<IziCommand>> = Box::leak(node).into();
            self.next = Some(pter);

	} else {
	    let mut pter: NonNull<LinkedList<IziCommand>> = Box::leak(node).into();
	    unsafe {
		pter.as_mut().next = self.next;
	    }
	    self.next = Some(pter);
	}
    }

    pub fn pop_left(&mut self) -> Option<IziCommand> {
        if self.next.is_none() {
            return None
        } 
	else {
	    let mut next = self.next.unwrap();
	    let only_one: bool = unsafe {next.as_mut().next.is_none()};
	    if only_one == true {
		let next_box = unsafe {
		    Box::from_raw(next.as_ptr())
		};
		self.next = None;
		next_box.value
	    } else {
		let next_of_next = unsafe { next.as_mut().next };
		let next_box = unsafe {
		    Box::from_raw(next.as_ptr())
		};
		self.next = next_of_next;
		next_box.value
	    }
	}
    }

    pub fn collect(&self) -> Vec<IziCommand> {
	let mut result = Vec::<IziCommand>::new();
	if self.next.is_none() {
            return result
	}

	let mut node = self.next.unwrap();
	unsafe {
            result.push(node.as_mut().value.as_ref().unwrap().clone());
            while node.as_mut().next.is_some() {
		node = node.as_mut().next.unwrap();
		result.push(node.as_mut().value.as_ref().unwrap().clone());
            }
	}
	return result;
    }
}

fn main() {
    let mut map_var:HashMap<&str, IziVar> = HashMap::new();
    map_var.insert("var_numb", IziVar {value: 0});
    println!("var_numb is: {}", map_var["var_numb"].value);

    let mut list: LinkedList<IziCommand> = LinkedList::<IziCommand>::new();
    list.push_left(IziCommand { value: 4 });
    list.push_left(IziCommand { value: 3 });
    list.push_left(IziCommand { value: 2 });
    list.push_left(IziCommand { value: 1 });

    let vec: Vec<IziCommand> = list.collect();
    for izicom in vec {
	println!("IziCommand.value = {}", izicom.value);
    }
}
