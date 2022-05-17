#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    long long mx, result = 0;
    for(int i =0; i < n; i++){
        long long m;
        cin >> m;
        mx = max(mx, m);
        result += mx-m;
    }
    cout << result;
}