default:
	clang -g main.cpp
	./a.out > plot.txt
	gnuplot -e "set term png; set out \"out.png\"; plot \"plot.txt\" with lines"
	open out.png
	
