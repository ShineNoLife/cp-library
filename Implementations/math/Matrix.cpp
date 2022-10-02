#include <bits/stdc++.h>
using namespace std;

struct Matrix{
    long long A[2][2] = {{0, 0}, {0, 0}};
    auto & operator [](int i){
        return A[i];
    }
    Matrix operator *(Matrix B){
        Matrix C;
        C[0][0] = C[0][1] = C[1][0] = C[1][1] = 0;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                for(int k = 0; k < 2; k++)
                    C[i][j]+=A[i][k]*B[k][j], C[i][j]%=MOD;
        return C;
    }
};
