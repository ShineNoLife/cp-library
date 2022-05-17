/*
Description: Z algorithm in O(n)
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> Zfunction(string s){
    int n = (int)s.size();
    vector<int> zf(n);
    zf[0] = n;
    for(int i = 1, l = 0, r = 0; i < n; i++){
        if(i <= r)
            zf[i] = min(r-i+1, (int)zf[i-l]);
        while(i+zf[i] < n && s[zf[i]] == s[i+zf[i]])
            zf[i]++;
        if(i+zf[i]-1 > r){
            l = i;
            r = i+zf[i]-1;
        }
    }
    return zf;
}

int main(){

}