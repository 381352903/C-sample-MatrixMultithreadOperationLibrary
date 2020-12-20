matrix: matrix.cpp
	g++ -std=c++11 matrix.cpp -o matrix.out -pthread
clean:
	rm matrix.out
