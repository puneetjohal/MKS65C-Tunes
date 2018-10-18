all: main.o ll.o tunes.o
	gcc -g main.o
run:
	gdb a.out
main.o: main.c
	gcc -g main.c
ll.o: ll.c ll.h
	gcc -g ll.c
tunes.o: tunes.c tunes.h
	gcc -g tunes.c
