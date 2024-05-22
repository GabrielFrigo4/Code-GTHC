use std::collections::HashMap;

fn main() {
	let text: String = String::from("eu trabalho no mercado de bananas");
	let pattern: String = String::from("anas");
	let text_len: usize = text.len();
	let pattern_len: usize = pattern.len();
	println!("Find sub-string text:\"{text}\":{text_len} pattern:\"{pattern}\":{pattern_len}");
	println!("{}", substr(&text, &pattern));
}

// https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/kmp.html
fn substr(text: &String, pattern: &String) -> usize {
	let dfa = create_dumb_dfa(pattern);
	for (key, value) in &dfa {
		println!("[{}: {:?}]", key, value);
	}

	let mut i: usize = 0;
	let mut j: usize = 0;

	for c in text.chars() {
		if j >= pattern.chars().count() {
			break;
		}
		i += 1;
		match dfa.get(&c) {
			Some(vec) => j = vec[j],
			_ => j = 0,
		}
	}

	if j == pattern.chars().count() {
		i-pattern.chars().count()
	}
	else {
		text.len()
	}
}

fn create_dumb_dfa(pattern: &String) -> HashMap<char, Vec<usize>> {
	let mut dfa: HashMap<char, Vec<usize>> = HashMap::new();
	for c in pattern.chars() {
		if dfa.get(&c) == Option::None {
			dfa.insert(c, vec![0; pattern.chars().count()]);
			for i in 0..pattern.chars().count() {
				for j in (1..(i+2)).rev() {
					let prefix: String = pattern[0..j].to_string();
					let mut sulfix: String = pattern[(i+1-j)..i].to_string();
					sulfix.push(c);

					if prefix == sulfix {
						dfa.get_mut(&c).unwrap()[i] = j;
						break;
					}
				}
			}
		}
	}
	
	dfa
}

// como eu não entendi, eu não programei :)
fn create_smart_dfa(pattern: &String) -> HashMap<char, Vec<usize>> {
	let mut dfa: HashMap<char, Vec<usize>> = HashMap::new();
	for c in pattern.chars() {
		if dfa.get(&c) == Option::None {
			dfa.insert(c, vec![0; pattern.chars().count()]);			
		}
	}

	dfa
}
