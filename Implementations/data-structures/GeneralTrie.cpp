#include <bits/stdc++.h>
using namespace std;

class Trie{
    struct Node{
        Node* child[26];
        int cnt[26];
        Node(){
            for(int i = 0; i < 26; i++)
                child[i] = NULL, cnt[i] = 0;
        }
    };
    Node* root;
    public:
        void trieInsert(str &s){
            Node* p = root;
            int n = sz(s);
            for(int i = 0; i < n; i++){
                int cur = s[i]-'0';
                if(p->child[cur] == NULL)
                    p->cnt[cur]++, p->child[cur] = new Node();
                p = p->child[cur];
            }
        }
        void trieErase(str &s){
            Node* p = root;
            int n = sz(s);
            for(int i = 0; i < n; i++){
                int cur = s[i]-'0';
                p->cnt[cur]--;
                p = p->child[cur];
            }
        }
}