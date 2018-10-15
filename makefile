all: main.o ll.o tunes.o
	gcc main.o
run:
	./a.out
main.o: main.c
	gcc -c main.c
ll.o: ll.c ll.h
	gcc -c ll.c
tunes.o: tunes.c tunes.h
	gcc -c tunes.c
