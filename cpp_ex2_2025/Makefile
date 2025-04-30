# melissaliebowitz@yahoo.com
CXX = clang++-18
CXXFLAGS =  -std=c++17 -Wall -g 

main: Main.cpp SquareMat.cpp SquareMat.hpp 
	$(CXX) $(CXXFLAGS) Main.cpp SquareMat.cpp -o main
	./main

test: SquareMatTest.cpp SquareMat.cpp SquareMat.hpp doctest.h
	$(CXX) $(CXXFLAGS) SquareMatTest.cpp SquareMat.cpp -o test
	./test

valgrind: main
	valgrind --leak-check=full --track-origins=yes ./main

clean:
	rm -f main test