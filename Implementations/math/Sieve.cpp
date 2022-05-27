#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
bool prime[MAXN+1];

void sieve(int n){
    memset(prime, true, sizeof(prime[0])*(n+1));
    prime[0] = prime[1] = false;
    for(int i = 2; i <= n; i++){
        if(prime[i]){
            for(int j = i*i; j <= n; j+=i)
                prime[j] = false;
        }
    }
}

int main(){

}
