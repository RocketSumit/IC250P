#..........................................
#   Name: Sumit Patidar
#   Roll no : B15237
#   Purpose : IC250 assignment, Q3
#   Date : 07/09/16
#..........................................

q3 : stack_using_queue.o my_functions.o
	cc -o q3 stack_using_queue.o my_functions.o `pkg-config --cflags --libs glib-2.0`
#include path to glib-2

stack_using_queue.o : stack_using_queue.c my_library.h
	cc -c stack_using_queue.c `pkg-config --cflags --libs glib-2.0`
#include path to glib-2

my_functions.o : my_functions.c my_library.h
	cc -c my_functions.c `pkg-config --cflags --libs glib-2.0`


clean:
	rm q3 stack_using_queue.o my_functions.o
