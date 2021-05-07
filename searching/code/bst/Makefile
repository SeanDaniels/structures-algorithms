CC = g++
CCFLAGS = -g -Wall -std=c++0x
DEPS = bst.h
OBJ = bst.o main.o
TARGET = example

%.o: %.cpp $(DEPS)
		$(CC) $(CCFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
		$(CC) $(CCFLAGS) -o $@ $^

clean:
	rm *.o
	rm $(TARGET)
