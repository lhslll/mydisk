CC=gcc
sniffer : sniffer.o
	$(CC) -Wall -g -o sniffer sniffer.o -lpcap
sniffer.o : sniffer.c
	$(CC) -c -g sniffer.c -lpcap
#-lpcap -I/usr/src/linux-headers-3.16.0-30-generic/include/config/touchscreen/
#IntArray.o : IntArray.cpp
#$(CC) -c -g IntArray.cpp
#MyString.o : MyString.cpp
#$(CC) -c -g MyString.cpp
clean :
	rm entry *.o
