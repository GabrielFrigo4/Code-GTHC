fn main() {
    println!("Hello, world!");
	println!("{}", str_test1());
	println!("{}", str_test2("_text1"));
	println!("{}", str_test3("_text1", "_text2"));
	println!("{}", str_test4("_text1"));
	println!("{}", str_test5("_text1", "_text2"));
}

fn str_test1() -> &'static str {
	"Hello, world!"
}

fn str_test2(_text1: &str) -> &'static str {
	"Hello, world!"
}

fn str_test3(_text1: &str, _text2: &str) -> &'static str {
	"Hello, world!"
}

fn str_test4(text1: &str) -> &str {
	&text1[1..]
}

fn str_test5<'a>(text1: &'a str, _text2: &str) -> &'a str {
	&text1[1..]
}
