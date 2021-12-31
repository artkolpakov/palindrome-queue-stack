CC=gcc --std=c99 -g

all: palindrome

palindrome: palindrome.c stack.o list.o queue.o dynarray.o
	$(CC) palindrome.c stack.o list.o queue.o dynarray.o -o palindrome

dynarray.o: dynarray.c dynarray.h
	$(CC) -c dynarray.c

list.o: list.c list.h
	$(CC) -c list.c

queue.o: queue.c queue.h
	$(CC) -c queue.c

stack.o: stack.c stack.h
	$(CC) -c stack.c

clean:
	rm -f *.o palindrome
