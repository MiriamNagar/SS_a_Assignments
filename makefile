CC = gcc
AR=ar
FLAGS= -Wall -g
OBJECTS_MAIN = main.o
LIB_OBJ_LOOP = advancedClassificationLoop.o basicClassification.o
LIB_OBJ_REC = advancedClassificationRecursion.o basicClassification.o

all: libclassloops.a libclassrec.a libclassloops.so libclassrec.so mains maindloop maindrec

loops: libclassloops.a

loopd: libclassrec.so

recursives: libclassrec.a

recursived: libclassloops.so

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a

maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so

maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so

libclassloops.a: $(LIB_OBJ_LOOP)
	$(AR) -rcs libclassloops.a $(LIB_OBJ_LOOP)

libclassrec.a: $(LIB_OBJ_REC)
	$(AR) -rcs libclassrec.a $(LIB_OBJ_REC)

libclassloops.so: $(LIB_OBJ_LOOP)
	$(CC) -shared -o libclassloopd.so $(LIB_OBJ_LOOP)

libclassrec.so: $(LIB_OBJ_REC)
	$(CC) -shared -o libclassrecursived.so $(LIB_OBJ_REC)

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c

.PHONY: clean all

clean:
	rm -f *.o *.a *.so mains maindloop maindrec