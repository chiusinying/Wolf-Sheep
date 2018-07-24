CC = g++
CXXFLAGS = -Wall -std=c++11 -I.

SOURCE = ./src/*.cc

all: Wolf-Sheep

Proteus: $(SOURCE)
	$(CC) $(SOURCE) $(CXXFLAGS) -o $@

run:
	./Wolf-Sheep

clean:
	rm Wolf-Sheep