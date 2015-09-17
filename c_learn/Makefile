CC=g++
hello : hello.o IntArray.o MyString.o TArray.h
	$(CC) -Wall -g -o hello hello.o IntArray.o MyString.o TArray.h
hello.o : hello.cpp
	$(CC) -c -g hello.cpp
IntArray.o : IntArray.cpp
	$(CC) -c -g IntArray.cpp
MyString.o : MyString.cpp
	$(CC) -c -g MyString.cpp
clean :
	rm hello *.o
