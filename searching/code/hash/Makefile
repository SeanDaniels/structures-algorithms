##
# Project Title
#
# @file
# @version 0.1
#
CC = g++
CCFLAGS = -g -Wall -std=c++0x
DEPS = hashTable.h
OBJ = hashTable.o main.o
TARGET = example

%.o: %.cc $(DEPS)
		$(CC) $(CCFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
		$(CC) $(CCFLAGS) -o $@ $^

clean:
	rm *.o
	rm $(TARGET)
