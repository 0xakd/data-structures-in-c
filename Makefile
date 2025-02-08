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


compile-hash_table:
	$(CC) $(CFLAGS) main.c hash_table/hash_table.c hash_table/dll.c -o bin/final


compile-adj_list:
	$(CC) $(CFLAGS) main.c graphs/dll.c graphs/graph.c graphs/hash_table.c  graphs/queue.c -o bin/final


clean:
	@echo "Removing everything except the source files"
	rm -rf bin && mkdir bin
