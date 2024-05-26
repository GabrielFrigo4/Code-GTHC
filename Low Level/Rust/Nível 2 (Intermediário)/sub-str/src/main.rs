// Usando Standard
use std::collections::HashMap;

// Power Mode
enum KmpDfa {
	Dumb,
	Smart,
}

// Função Main (ponto de partida)
fn main() {
	let text: String = String::from("trabalhar no mercado de bananas");
	let pattern: String = String::from("anas");
	let text_len: usize = text.len();
	let pattern_len: usize = pattern.len();
	println!("text:\"{text}\":{text_len}");
	println!("pattern:\"{pattern}\":{pattern_len}");
	println!("{}", substr(&text, &pattern, KmpDfa::Dumb));
	println!("{}", substr(&text, &pattern, KmpDfa::Smart));
}


/*
 * https://www.ime.usp.br/~pf/estruturas-de-dados/aulas/kmp.html
 * Código da busca KMP
 */


// Achar Sub-String
fn substr(text: &String, pattern: &String, kmp_dfa: KmpDfa) -> usize {
	if text.len() == 0 || pattern.len() == 0 {
		return 0;
	}

	let dfa = match kmp_dfa {
		KmpDfa::Smart => create_smart_dfa(pattern),
		KmpDfa::Dumb => create_dumb_dfa(pattern)
	};

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


/*
 * Construção do DFA
 */


// Criar Vetor
fn create_dumb_vec(pattern: &String, c: char) -> Vec<usize> {
	let mut dfa_vec: Vec<usize> = vec![0; pattern.chars().count()];
	for i in 0..pattern.chars().count() {
		for j in (1..(i+2)).rev() {
			let prefix: String = pattern[0..j].to_string();
			let mut sulfix: String = pattern[(i+1-j)..i].to_string();
			sulfix.push(c);

			if prefix == sulfix {
				dfa_vec[i] = j;
				break;
			}
		}
	}
	dfa_vec
}

// Criar DFA
fn create_dumb_dfa(pattern: &String) -> HashMap<char, Vec<usize>> {
	let mut dfa: HashMap<char, Vec<usize>> = HashMap::new();
	for c in pattern.chars() {
		if dfa.get(&c) == Option::None {
			let dfa_vec: Vec<usize> = create_dumb_vec(pattern, c);
			dfa.insert(c, dfa_vec);
		}
	}

	dfa
}


/*
 * Construção eficiente do DFA
 */

// Criar DFA
fn create_smart_dfa(pattern: &String) -> HashMap<char, Vec<usize>> {
	let mut dfa: HashMap<char, Vec<usize>> = HashMap::new();
	for c in pattern.chars() {
		if dfa.get(&c) == Option::None {
			dfa.insert(c, vec![0; pattern.chars().count()]);
		}
	}

	let mut x: usize = 0;
	let mut j: usize = 0;
	for c in pattern.chars() {
		for (_, value) in &mut dfa {
			value[j] = value[x];
		}

		let sv: &mut Vec<usize> = dfa.get_mut(&c).unwrap();
		sv[j] = j+1;
		if j > 0 {
			x = sv[x];
		}

		j += 1;
	}

	dfa
}
