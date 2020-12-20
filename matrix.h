#ifndef CIRCLE_H
#define CIRCLE_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<thread>
#include<ctime>
using namespace std;
//
// @brief: matrix calculation
// @copyright: Tairun Meng
// @birth: created by Tairun Meng on 2020-12-13
// @version: V1.0.2
// @revision: last revised by Tairun Meng by 2020-12-19
//

/********************************************
*@function: use this class to describe a matrix and do transpose, multiplication the matrix or
* display the matrix. The transpose and multiplication is implemented via multi-threads
* we also utilized the spacial locality when we traverse elements in the matrix
*@para: myMatrix is used to store the matrix infomation. type of it is vector<vector<int> >
********************************************/
class Matrix {
public:
    vector<vector<int> > myMatrix;
    Matrix transposing();
    Matrix operator*(const Matrix& matrix);
    void display();
};

// @brief: transpose the matrix in the class Matrix
// @param: void
// @ret: return the transposed matrix
// @birth: created by Tairun Meng on 2020-12-13
Matrix Matrix::transposing() {
    Matrix res;
    vector<vector<int> > temp(myMatrix[0].size(),vector<int>(myMatrix.size()));
    res.myMatrix = temp;

    auto mulTranspose=[&](int startRow,int endRow){
        for(int i=startRow;i<endRow;++i){
            for(int j=0;j<myMatrix[0].size();++j){
                res.myMatrix[j][i]=myMatrix[i][j];
            }
        }
    };

    int row=myMatrix.size();
    //just use 4 threads at here
    int div=row/4;
    thread t1(mulTranspose, 0, div);
    thread t2(mulTranspose, div, 2 * div);
    thread t3(mulTranspose, 2 * div, 3 * div);
    thread t4(mulTranspose, 3 * div, row);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return res;
}

// @brief: multiply two matrix via 4 threads
// @param: void
// @ret: return the multiplied matrix
// @birth: created by Tairun Meng on 2020-12-13
Matrix Matrix::operator*(const Matrix& matrix) {
    int row = myMatrix.size();
    int col = matrix.myMatrix[0].size();

    if(myMatrix[0].size()!=matrix.myMatrix.size()){
        printf("err: Illegal operation.\n");
        return matrix;
    }

    vector<vector<int> > temp(row, vector<int>(col));
    Matrix res;
    res.myMatrix = temp;

    int m = myMatrix.size();
    int t = myMatrix[0].size();
    int n = matrix.myMatrix[0].size();

    auto mulMulti=[&](int rowStart, int rowEnd){
        // ikj is faster than ijk (memory access issues)
        for (int i = rowStart; i < rowEnd; ++i)
            for (int k = 0; k < t; ++k)
            {
                int s = myMatrix[i][k];
                for (int j = 0; j < n; ++j)
                    res.myMatrix[i][j] += s * matrix.myMatrix[k][j];
            }
    };
    //just use 4 threads at here
    int div=row/4;
    thread t1(mulMulti, 0, div);
    thread t2(mulMulti, div, 2 * div);
    thread t3(mulMulti, 2 * div, 3 * div);
    thread t4(mulMulti, 3 * div, row);
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return res;
}

// @brief: display the matrix in the Matrix class
// @param: void
// @ret: void
// @birth: created by Tairun Meng on 2020-12-13
void Matrix::display()
{
    for (int i = 0; i < myMatrix.size(); i++) {
        for (int j = 0; j < myMatrix[i].size(); j++) {
            cout << myMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}

#endif