all : demo

demo : main.o strategy.o
	g++ -o demo main.o strategy.o
	
main.o : main.cpp strategy.h
	gcc -std=c++11 -g -c main.cpp

strategy.o : strategy.cpp strategy.h
	gcc -std=c++11 -g -c strategy.cpp
	
.PHONY : clean
clean :
	rm -f *.o demo