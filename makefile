all: driver.o ll.o tunes.o
	gcc driver.o
debug: driver.c ll.c ll.h tunes.c tunes.h
	gcc -g -c driver.c tunes.h tunes.c ll.h ll.c
	gcc -g driver.o
run:
	./a.out
driver.o: driver.c
	gcc -c driver.c
ll.o: ll.c ll.h
	gcc -c ll.c
tunes.o: tunes.c tunes.h
	gcc -c tunes.c
clean:
	rm *.o
