#.........................................................
#   Name: Sumit Patidar
#   Roll no: B15237
#   Purpose: Assignment 04, Q1
#   Date: 03/09/2016
#..........................................................

q1 : bal_parenthesis.o my_functions.o
	cc -o q1 bal_parenthesis.o my_functions.o `pkg-config --cflags --libs glib-2.0`

bal_parenthesis.o : bal_parenthesis.c my_library.h
	cc -c bal_parenthesis.c `pkg-config --cflags --libs glib-2.0`

my_functions.o : my_functions.c my_library.h
	cc -c my_functions.c `pkg-config --cflags --libs glib-2.0`

clean:
	rm q1 bal_parenthesis.o my_functions.o
