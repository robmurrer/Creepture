CXX=clang++ -g -Wall -Iinclude/ -Linclude/ -lBox2D -v
#CXXFLAGS=-g -Wall -Iinclude/ -Linclude/ -lBox2D -v

BIN=creepture
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

default:
	rm -f main.o
	make build
	valgrind ./creepture

build: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

clean:
	rm -f *.o
	rm -f $(BIN)
