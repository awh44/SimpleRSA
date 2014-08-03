run: rsa.c ../BitVector/BitVector.c ../BitVector/BitVector.h
	gcc -o rsa.out rsa.c ../BitVector/BitVector.c -Wall
	./rsa.out
	rm rsa.out
