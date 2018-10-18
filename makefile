all: driver.o ll.o tunes.o
	gcc driver.o
run:
	./a.out
driver.o: driver.c
	gcc -c driver.c
ll.o: ll.c ll.h
	gcc -c ll.c
tunes.o: tunes.c tunes.h
	gcc -c tunes.c
