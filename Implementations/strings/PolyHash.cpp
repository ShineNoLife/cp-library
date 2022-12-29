const int maxn = 2e5 + 250;
const int nMOD = 3;
const int modulo[] = {(int)1e9 + 7, (int)1e9 + 4777, (int)1e9 + 10777};
// 'z' is 122 is ascii
const int BASE = 333;
int pw[nMOD][maxn + 1];
 
void precalc(){
    for(int j = 0; j < nMOD; j++){
        pw[j][0] = 1;
        for(int i = 1; i <= maxn; i++)
            pw[j][i] = (1ll * pw[j][i - 1] * BASE) % modulo[j];
    }
}
  
struct PolyHash{
    int val[nMOD];
  
    PolyHash() { mem(val, 0); }
 
    PolyHash(const string &s) {
        mem(val, 0);
 
        for(int j = 0; j < nMOD; j++)
            for(int i = 0; i < sz(s); i++)
                val[j] = (1ll * val[j] * BASE + s[i]) % modulo[j];
    }
 
    bool operator < (const PolyHash &x) const {
        for(int i = 0; i < nMOD; i++) 
            if(val[i] != x.val[i]) 
                return (val[i] < x.val[i]);
 
        return false;
    }
};
