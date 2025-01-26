# Variables
CC = gcc
CFLAGS = -Wno-implicit-function-declaration

run:
	./bin/final
	

compile-dll: 
	$(CC) $(CFLAGS) main.c doubly-linked-list/dll.c -o bin/final


compile-stack:
	$(CC) $(CFLAGS) main.c stack/stack.c doubly-linked-list/dll.c -o bin/final


compile-queue:
	$(CC) $(CFLAGS) main.c queue/queue.c doubly-linked-list/dll.c -o bin/final


clean:
	@echo "Removing everything except the source files"
	rm -rf bin && mkdir bin
