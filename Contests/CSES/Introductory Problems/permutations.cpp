#include <bits/stdc++.h>
 
#define ll long long
#define str string
#define db double
 
#define pi pair<int, int>
#define pl pair<ll, ll>
#define pd pair<db, db>
 
#define vi vector<int>
#define vl vector<ll>
#define vd vector<db>
#define vb vector<bool>
#define vs vector<str>
#define vpi vector<pi>
#define vpl vector<pl>
#define vpd vector<pd>
#define IOS; ios_base::sync_with_stdio(false); cin.tie(NULL);
 
//pairs
#define mp make_pair
#define f first
#define s second
 
//vectors
#define pb push_back
#define pf push_front
 
//loops
#define FOR(i, a, b) for(int i=(int)a;i<(int)b;++i)
#define ROF(i, a, b) for(int i=(int)a-1;i>=(int)b;i--)
#define rep(a, x) for(auto& a : x)
 
const int MOD = 1e9+7;
const ll INF = 1e18;
 
using namespace std;
 
int main(){
    IOS;
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    if(n <= 3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    int l = 1, r = 2;
    while(r <= n){
        cout << r << " ";
        r+=2;
    }
    while(l <= n){
        cout << l << " ";
        l+=2;
    }
}