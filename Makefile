debug:
	gcc -D DEBUG -Wall cftp.c -g -o cftp
release:
	gcc -Wall cftp.c -o cftp
clean:
	rm -rf *.o cftp