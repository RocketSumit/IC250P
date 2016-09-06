q3 : stack_using_queue.o
	cc -o q3 stack_using_queue.o `pkg-config --cflags --libs glib-2.0`

stack_using_queue.o : stack_using_queue.c
	cc -c stack_using_queue.c `pkg-config --cflags --libs glib-2.0`

clean:
	rm q1 stack_using_queue.o
