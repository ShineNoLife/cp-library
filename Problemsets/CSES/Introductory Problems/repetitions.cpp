#include <iostream>
#include <bits/stdc++.h>:
using namespace std;
 
int main(){
    string s;
    cin >> s;
    int result = 1, c = 0;
    char k ='A';
    for(char d : s){
        if(d==k){
            ++c;
            result = max(c, result);
        }
        else{
            k=d;
            c=1;
        }
    }
    cout << result;
}