#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    unsigned long long k, m, s = 0;
    k = n;
    while(--n){
        cin >> m;
        s+=m;
        k+=n;
    }
    cout << k-s << endl;
    return 0;
}