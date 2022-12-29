const int maxn = 2e5 + 250;
const int nMOD = 2;
const int modulo[] = {(int)1e9 + 7, (int)1e9 + 3777, (int)1e9 + 10777, (int)1e9 + 19777};
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
    int val[nMOD], len;
  
    PolyHash() { mem(val, 0), len = 0; }
 
    PolyHash(const string &s){
        mem(val, 0), len = sz(s);
 
        for(int j = 0; j < nMOD; j++)
            for(int i = 0; i < sz(s); i++)
                val[j] = (1ll * val[j] * BASE + s[i]) % modulo[j];
    }
 
    void addFront(char c){
        for(int j = 0; j < nMOD; j++)
            val[j] = (1ll * c * pw[j][len] + val[j]) % modulo[j];

        len++;
    }

    void addBack(char c){
        len++;

        for(int j = 0; j < nMOD; j++)
            val[j] = (1ll * val[j] * BASE + c) % modulo[j];
    }

    bool operator < (const PolyHash &x) const {
        for(int i = 0; i < nMOD; i++) 
            if(val[i] != x.val[i]) 
                return (val[i] < x.val[i]);
 
        return false;
    }
};
