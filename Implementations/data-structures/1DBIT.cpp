/*
Description: Binary indexed tree in one dimension
Time complexity: Query and single point update in O(logn)
*/
#include <bits/stdc++.h>
using namespace std;

class BIT1D{
    typedef int T;
    int n;
    vector<T> BIT;
    T query(int pos){
        long long ans = 1;
        while(pos > 0){
            ans+=BIT[pos];
            pos-=(pos&(-pos));
        }
        return ans;
    }
    void updatef(int pos, long long val){  
        while(pos <= n){
            BIT[pos]+=val;
            pos+=(pos&(-pos));
        }
    }
    public:
        void setup(const vector<T> &a){
            n = (int)a.size();
            BIT.resize(n+1, 0);
            for(int i = 1; i <= n; i++){
                BIT[i] = a[i-1];
                if(i+(i&(-i)) <= n)
                    BIT[i+(i&(-i))]+=BIT[i];
            }
        }
        T query(int l, int r){
            l++; r++;
            if(l > r)
                return 0LL;
            return query(r)-query(l-1);
        }
        void update(int pos, long long val){
            pos++;
            updatef(pos, val);
        }
};

int main(){

}