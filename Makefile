debug:
	gcc -D DEBUG -Wall cftp.c types/linkedlist.h types/linkedlist.c types/hashtable.h types/hashtable.c -g -o cftp
release:
	gcc -Wall cftp.c types/linkedlist.h types/linkedlist.c types/hashtable.h types/hashtable.c -o cftp
clean:
	rm -rf *.o cftp