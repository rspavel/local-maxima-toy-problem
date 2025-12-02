all: localMaximaFinder

localMaximaFinder: localMaximaFinder.o
	clang++ localMaximaFinder.o -o localMaximaFinder

localMaximaFinder.o: localMaximaFinder.cpp localMaximaFinder.hpp
	clang++ -std=c++23 -c localMaximaFinder.cpp

clean:
	rm -f ./localMaximaFinder.o ./localMaximaFinder

