/*
Description: range minimum and maximum query in O(1), with O(nlogn) preparation time
*/
#include <bits/stdc++.h>
using namespace std;

const int LOG = 19;
const int MAXN = 1e6+77;
int n;
int v[MAXN], lg2[MAXN], sp[MAXN][LOG+1];

int query(int l, int r){
	int last = lg2[r-l+1];
	return min(sp[l][last], sp[r-(1 << last)+1][last]);
}

void setup(){
	lg2[0] = 0;
	for(int i = 1; i < MAXN; i++)
		lg2[i] = lg2[i/2]+1;
	for(int i = 0; i < n; i++)
		sp[i][0] = v[i];
	for(int j = 1; j <= LOG; j++){
		for(int i = 0; i < n-(1 << j)+1; i++){
			sp[i][j] = min(sp[i][j-1], sp[i+(1 << (j-1))][j-1]);
		}
	}
}

int main(){

}
