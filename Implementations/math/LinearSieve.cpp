/*
Description: Sieve of Eratosthenes in O(n)
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
bool composite[MAXN+1];
vector<int> prime;

void sieve(int n){
    memset(composite, false, sizeof(composite[0])*(n+1));
    composite[0] = composite[1] = true;
    for(int i = 2; i <= n; i++){
        if(!composite[i])
            prime.push_back(i);
        for(int j = 0; j < prime.size() && 1ll*i*prime[j] <= n; j++){
            composite[i*prime[j]] = true;
            if(i%prime[j] == 0)
                break;
        }
    }
}

int main(){

}
