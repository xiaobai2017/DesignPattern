all : demo

demo : main.o state.o
	g++ -o demo main.o state.o
	
main.o : main.cpp state.h
	gcc -std=c++11 -g -c main.cpp

state.o : state.cpp state.h
	gcc -std=c++11 -g -c state.cpp
	
.PHONY : clean
clean :
	rm -f *.o demo