debug:
	gcc -D DEBUG -Wall cftp.c types/linkedlist.h types/linkedlist.c -g -o cftp
release:
	gcc -Wall cftp.c types/linkedlist.h types/linkedlist.c -o cftp
clean:
	rm -rf *.o cftp