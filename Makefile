# Variables
CC = gcc
CFLAGS = -Wno-implicit-function-declaration


compile-dll: 
	$(CC) $(CFLAGS) main.c doubly-linked-list/dll.c -o bin/final


clean:
	@echo "Removing everything except the source files"
	rm -rf bin && mkdir bin
