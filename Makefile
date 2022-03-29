main: solution.o main.o
	g++ -o GT_Project_1 main.o solution.o

solution.o: solution.cpp solution.h
	g++ -c solution.cpp

main.o: main.cpp solution.h graph_input.h
	g++ -c main.cpp

clean:
	rm solution *.o
