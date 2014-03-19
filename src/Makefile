CXX=clang++ -g -Wall -Iinclude/ -Linclude/ -lBox2D -v -std=c++11
#CXXFLAGS=-g -Wall -Iinclude/ -Linclude/ -lBox2D -v

BIN=creepture
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

default:
	make runvg
	cd ../log; make

runvg:
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
