CXX=clang++ -g -Wall -Iinclude/ -Linclude/ -lBox2D -v -std=c++11
#CXXFLAGS=-g -Wall -Iinclude/ -Linclude/ -lBox2D -v

BIN=creepture
SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

default:
	#make runvg
	make run
	cd ../log; make
	#make genplots
	#make logcopy
	#make lldb
	#make log

genplots:
	gnuplot -e "set term png; set out \"../log/gatmp/fitness.png\"; \
	set xlabel \"Generation\"; set ylabel \"Fitness\"; set grid; \
	plot \"../log/gatmp/generations.txt\" using 2 title 'Best Fitness' with lines, \
	\"../log/gatmp/generations.txt\" using 3 title 'Avg Fitness' with lines"
	open ../log/gatmp/fitness.png
	

logcopy:
	mkdir  ../log/garuns/`cat ../log/gatmp/title.txt`
	cp ../log/gatmp/* ../log/garuns/`cat ../log/gatmp/title.txt`/
	cp ../log/gatmp/chromosome.txt ../log/chromosomes/test.txt 


lldb:
	make build
	lldb ./creepture
runtb:
	cd ../lzy/Testbed/; make

log:
	#make runvg
	make run
	cd ../log; make

run:
	rm -f main.o
	make build
	time ./creepture
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
