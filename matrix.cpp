#include "matrix.h"

int main(){
    //test cases
        //Initialize three matrix A, B, C in this way
        Matrix A;
        A.myMatrix ={{ 1,2 },{ 3,4 }};
        Matrix B;
        B.myMatrix = { {1,3},{3,2} ,{1,4},{9,8}};
        Matrix C;
        C.myMatrix = { {1,3,1},{3,2,2} };
        Matrix D;
        
        int N=500;
        D.myMatrix=vector<vector<int>>(N,vector<int>(N));
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                D.myMatrix[i][j]=rand()%100;
            }
        }
        clock_t start=clock();
        //calculate large scale multiplication time
        D*D;
        clock_t finish=clock();
        printf("%d*%d dimention matrix multiplication calculation\ntakes %.3f seconds\n",N,N,(long)(finish-start)/1E6);
    
        //display A,B,C
        cout<<"The matrix A is:"<<endl;
        A.display();
        cout<<"The matrix B is:"<<endl;
        B.display();
        cout<<"The matrix C is:"<<endl;
        C.display();
        cout<<endl;
        //Transpose of A
        cout << "The transpose of matrix A:" << endl;
        A.transposing().display();

        cout << "The transpose of matrix B:" << endl;
        B.transposing().display();

        //Transpose of C
        cout << "\n\nThe transpose of matrix C:" << endl;
        C.transposing().display();


        //C*A
        cout << "\n\nC * A:" << endl;
        if (C.myMatrix[0].size() == A.myMatrix.size()) {
            (C*A).display();
        }
        else {
            cout << "Illegal operation!" << endl;
        }

        //A*C
        cout << "\n\nA * C" << endl;
        (A*C).display();

        //C*C
        cout << "\n\nC * C" << endl;
        (C.transposing()*C).display();
        return 0;
}
