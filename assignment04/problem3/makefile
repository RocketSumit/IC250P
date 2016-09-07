#..........................................
#   Name: Sumit Patidar
#   Roll no : B15237
#   Purpose : IC250 assignment, Q3
#   Date : 07/09/16
#..........................................

q3 : stack_using_queue.o
	cc -o q3 stack_using_queue.o `pkg-config --cflags --libs glib-2.0`
#include path to glib-2

stack_using_queue.o : stack_using_queue.c
	cc -c stack_using_queue.c `pkg-config --cflags --libs glib-2.0`
#include path to glib-2

clean:
	rm q3 stack_using_queue.o
