#include <bits/stdc++.h>
using namespace std;

struct Matrix{
    long long A[2][2];
    auto & operator [](int i){
        return A[i];
    }
    Matrix(){
        mem(A, 0);
    }
    Matrix operator *(Matrix B){
        Matrix C;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    C[i][j]+=A[i][k]*B[k][j], C[i][j]%=MOD;
        return C;
    }
};
