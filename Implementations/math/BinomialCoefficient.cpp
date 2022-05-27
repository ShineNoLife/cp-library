#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 1e6;
int fact[MAXN+1], inverse[MAXN+1];

long long binpow(long long a, long long b){
    long long ans = 1;
    while(b){
        if(b&1)
            ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return ans;
}

void FactSetup(){
    fact[0] = inverse[0] = inverse[1] = 1;
    for(int i = 2; i <= MAXN; i++)
        fact[i] = (fact[i-1]*i)%MOD;
}

long long C(int n, int k){
    if(k > n) 
        return 0;
    return ((fact[n]*binpow(fact[k], MOD-2))%MOD*binpow(fact[n-k], MOD-2))%MOD;
}

int main(){

}

