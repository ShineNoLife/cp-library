#include <bits/stdc++.h>
using namespace std;

const int LIM = 30;

struct Node{
    Node* child[2];
    int cnt;
    Node(){
        for(int i = 0; i < 2; i++)
            child[i] = NULL;
        cnt = 0;
    }
};
Node* root = new Node();

void trieInsert(int x){
    Node* p = root;
    for(int i = LIM; i >= 0; i--){
        int bit = ((x >> i) & 1);
        if(p->child[bit] == NULL)
            p->child[bit] = new Node();
        p = p->child[bit];
    }
    p->cnt++;
}

void trieErase(int x){
    Node* p = root;
    for(int i = LIM; i >= 0; i--){
        int bit = ((x >> i) & 1);
        p = p->child[bit];
    }
    p->cnt--;
}
