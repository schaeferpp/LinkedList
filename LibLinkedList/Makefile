all: linkedlist

linkedlist: linkedlist.o
	ar rcs liblinkedlist.a LinkedList.o
	rm LinkedList.o
	
linkedlist.o:
	gcc -c LinkedList.c
