q4 : transpose_sparseMatrix.o my_functions.o
	cc -o q4 transpose_sparseMatrix.o my_functions.o

transpose_sparseMatrix.o : transpose_sparseMatrix.c my_library.h
	cc -c transpose_sparseMatrix.c

my_functions.o : my_functions.c my_library.h
	cc -c my_functions.c

clean:
	rm q1 transpose_sparseMatrix.o my_functions.o
