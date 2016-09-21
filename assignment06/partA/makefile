#.............................................................................
   #Name: Sumit Patidar
   #Roll no: B15237
   #Purpose: Assignment 06, part C
   #Date: 21/09/2016
 #............................................................................
p1: my_functions.o main.o
	cc -o p1 my_functions.o main.o -g

my_functions.o: my_library.h my_functions.c
	cc -c my_functions.c -g

main.o: my_functions.c main.c my_library.h
	cc -c my_functions.c main.c -g

clean:
	rm p1 my_functions.o main.o
