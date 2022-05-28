/*
Description: Binary indexed tree in two dimensions
Time complexity: Query and single point update in O(lognlogm)
*/
#include <bits/stdc++.h>
using namespace std;

class BIT2D{
    typedef int T;
    int n, m;
    vector<vector<T>> BIT;
    T query(int x, int y){
        T ans = 0;
        int y1;
        while(x > 0){
            int y1 = y;
            while(y1 > 0){
                ans+=BIT[x][y1];
                y1-=(y1&(-y1));
            }
            x-=(x&(-x));
        }
        return ans;
    }
    void updatef(int x, int y, long long val){
        int y1;
        while(x <= n){
            int y1 = y;
            while(y1 <= m){
                BIT[x][y1]+=val;
                y1+=(y1&(-y1));
            }
            x+=(x&(-x));
        }
    }
    public: 
        void setup(const vector<vector<T>> &a){
            n = (int)a.size(); m = (int)a[0].size();
            BIT.resize(n+1, {});
            for(int i = 0; i <= n; i++)
                BIT[i].resize(m+1, 0);
        }
        T query(int x, int y, int u, int v){
            //zero indexed arrays
            x++; y++; u++; v++;
            if(x > u || y > v)
                return 0LL;
            return query(u, v)-query(x-1, v)-query(u, y-1)+query(x-1, y-1);
        }
        void update(int x, int y, long long val){
            //zero indexed arrays
            x++; y++;
            updatef(x, y, val);
        }
        void debug(){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++)
                    cout << BIT[i][j] << " ";
                cout << '\n';
            }
        }
};

int main(){

}