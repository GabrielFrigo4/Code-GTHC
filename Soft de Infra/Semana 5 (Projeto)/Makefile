default:
	make build
	make run

build:
	gcc -O2 -m64 -march=native -mrdrnd -Iheader/ code/*.c -o gcds

run:
	./gcds
