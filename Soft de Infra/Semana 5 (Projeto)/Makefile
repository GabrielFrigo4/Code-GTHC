default:
	make build
	make run

build:
	gcc -O2 -m64 -march=native -mrdrnd -Iheader/ code/*.c code/game/*.c -o clsa

run:
	./clsa
