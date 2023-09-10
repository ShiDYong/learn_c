demo:	f1.o f2.o main.o
	gcc -o demo f1.o f2.o main.o

f1.o:	f1.c f1.h f2.h
	gcc -c f1.c

main.o: main.c f1.h
	gcc -c main.c

f2.o:	f2.c f1.h f2.h
	gcc -c f2.c

#CC=gcc
#CFLAGS=-Wall -Wextra -Wpedantic -std=c99
#demo: main.o f1.o f2.o
#	$(CC) -o demo main.o f1.o f2.o $(CFLAGS)
#
#main.o: main.c f1.h
#	$(CC) -c main.c $(CFLAGS)
#
#f1.o: f1.c f1.h f2.h
#	$(CC) -c f1.c $(CFLAGS)
#
#f2.o: f2.c f1.h f2.h
#	$(CC) -c f2.c $(CFLAGS)

