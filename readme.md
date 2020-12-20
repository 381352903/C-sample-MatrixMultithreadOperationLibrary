****************************************************************************************************************************
* Matrix multi-threads operation library
* @Author tairunmeng
* @Date Dec.19.2020
****************************************************************************************************************************
I implemented the matrix operations including multiplication and transpose based on multi-thread. The library file is matrix.h and the file matrix.cpp runs some test cases.

To run this file, firstly execute the command line
make
in the terminal, it will compile the file via c++ 11. Then execute
./matrix.out
you can see the test cases and the result.

Here I utilize 4 threads to do tasks in transposing() and operator*(const Matrix& matrix). Actually we can decide how many threads we use according to our computer architecture. I also utilized spatial locality when I am iterating elements in the matrix which also can improve performance. I use vector<vector<int> > to store our matrix information which might be a little bit slower than using array int[M][N] type. But I feel vector is more extendable and convenient to maintain.

In my test cases, I tested large scale matrix multiplication time, small scale matrix multiplication results and transpose results. If you have any question, feel free to contact me :)

tairunmeng@gmail.com
