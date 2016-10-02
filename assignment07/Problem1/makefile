p1: main.o my_functions.o 
	cc -o p1 main.o my_functions.o

main.o: main.c my_functions.c my_library.h
	cc -c main.c my_functions.c

my_functions.o: my_functions.c my_library.h
	cc -c my_functions.c

clean:
	rm p1 main.o my_functions.o
