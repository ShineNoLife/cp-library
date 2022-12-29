const int maxn = 2e5 + 250;
const int nMOD = 2;
const int modulo[] = {(int)1e9 + 2277, (int)1e9 + 5277};
// 'z' is 122 is ascii
const int BASE = 303;
int pw[nMOD][maxn];

void precalc(){
    for(int j = 0; j < nMOD; j++){
        pw[j][0] = 1;
        for(int i = 1; i < maxn; i++)
            pw[j][i] = (1LL * pw[j][i - 1] * BASE) % modulo[j];
    }
}
 
struct Hash{
    int val[nMOD];
 
    Hash() { mem(val, 0); }

    Hash(const string &s) {
        mem(val, 0);
        
        for(int j = 0; j < nMOD; j++)
            for(int i = 0; i < sz(s); i++)
                val[j] = (val[j] + 1ll * s[i] * pw[j][i]) % modulo[j];
    }

    bool operator < (const Hash &x) const {
        for(int i = 0; i < nMOD; i++) 
            if(val[i] != x.val[i]) 
                return (val[i] < x.val[i]);

        return false;
    }
};