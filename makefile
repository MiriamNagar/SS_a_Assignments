CC = gcc
AR=ar
FLAGS= -Wall -g
OBJECTS_MAIN = main.o
LIB_OBJ = my_mat.o

all: my_mat.a connections

connections: $(OBJECTS_MAIN) my_mat.a
	$(CC) $(FLAGS) -o connections $(OBJECTS_MAIN) my_mat.a

my_mat.a: $(LIB_OBJ)
	$(AR) -rcs my_mat.a $(LIB_OBJ)

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c

main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c


.PHONY: clean all

clean:
	rm -f *.o *.a connections
