#........................................
#   Name : Sumit Patidar
#   Roll no : B15237
#   Purpose : IC250 assignment 04, Q4
#   Date : 07/09/16
#.........................................

q4 : transpose_sparseMatrix.o my_functions.o
	cc -o q4 transpose_sparseMatrix.o my_functions.o

transpose_sparseMatrix.o : transpose_sparseMatrix.c my_library.h
	cc -c transpose_sparseMatrix.c

my_functions.o : my_functions.c my_library.h
	cc -c my_functions.c

clean:
	rm q4 transpose_sparseMatrix.o my_functions.o
