#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    int n, m, A[256][256];

    auto & operator [](int i) {
        return A[i];
    }

    Matrix() {
        mem(A, 0);
    }

    Matrix(int _n, int _m) {
        n = _n, m = _m;

        mem(A, 0);
    }

    Matrix operator *(Matrix B) {
        Matrix C(n, B.m);
        
        for(int k = 0; k < m; k++) {
            for(int i = 0; i < n; i++) {
                if (!A[i][k]) continue;
                
                for(int j = 0; j < B.m; j++) {
                    if (!B[k][j]) continue;

                    C[i][j] = (1LL * C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }
};
