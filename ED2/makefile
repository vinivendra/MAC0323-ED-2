ep2: main.o Point.o Distance.o
	gcc main.o Point.o Distance.o -g -o ep2 -lm

main.o: main.c
	gcc -c main.c -g -ansi -pedantic -Wall

Point.o: Point.c
	gcc -c Point.c -g -ansi -pedantic -Wall

Distance.o: Distance.c
	gcc -c Distance.c -g -ansi -pedantic -Wall
    
clean:
	rm -f *.o
