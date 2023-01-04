CC = gcc
FLAGS= -Wall -g

all: txtfind isort

txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.o

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.o

txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c


.PHONY: clean all

clean:
	rm -f *.o *.a txtfind isort