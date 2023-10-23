bool gaussian(vector<vector<ll>> A, vector<ll> &res) {
    int n = A.size();
    int m = sz(A[0]) - 1;

    //row position of each variable
    vector<ll> pos(m, -1);
    for (int row = 0, col = 0; row < n && col < m; col++) {
        for (int i = row; i < n; i++) {
            if (A[i][col]) {
                swap(A[row], A[i]);

                break;
            }
        }

        if (!A[row][col]) continue;

        pos[col] = row;

        for (int i = 0; i < n; i++) {
            if (i == row) continue;

            //multiplication is the same as division modulo 3

            //A[i][col] / A[row][col]
            ll c = (A[i][col] * A[row][col]) % 3;
            for (int j = col; j <= m; j++) {
                //A[i][j] -= A[row][j] * c;

                A[i][j] -= (A[row][j] * c) % 3;

                if (A[i][j] < 0) A[i][j] += 3;
            }
        }

        row++;
    }

    res.assign(m, 0);
    for (int i = 0; i < m; i++) {
        if (pos[i] != -1) {
            // A[pos[i]][m] / A[pos[i]][i];

            res[i] = (A[pos[i]][m] * A[pos[i]][i]) % 3;
        }
    }

    for (int i = 0; i < n; i++) {
        int total = 0;
        
        for (int j = 0; j < m; j++) 
            total = (total + res[j] * A[i][j]) % 3;

        if (total != A[i][m])
            return false; 
    }
    
    return true;
}