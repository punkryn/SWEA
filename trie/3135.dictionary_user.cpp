// #include <iostream>
// using namespace std;

#define ACNT 26
#define MAXN 1000001

struct Trie;
Trie* root;

Trie* myAlloc();
int poolCnt;

struct Trie{
    int child;
    bool finish;
    Trie* _children[ACNT];

    void Insert(const char* str){
        child++;
        if(*str == '\0'){
            finish = true;
            return;
        }

        if(_children[*str - 'a'] == nullptr) _children[*str - 'a'] = myAlloc();
        _children[*str - 'a']->Insert(str + 1);
    }

    int Find(const char* str){
        if(*str == '\0') return child;

        int cur = *str - 'a';
        if(_children[cur] == nullptr) return 0;
        return _children[cur]->Find(str + 1);
    }

    void clear(){
        child = 0;
        finish = false;
        for(int i = 0; i < ACNT; i++){
            _children[i] = nullptr;
        }
    }
};

Trie Node[MAXN];
Trie* myAlloc(){
    Trie* ret = &Node[poolCnt++];
    ret->clear();
    return ret;
}

void init(void) {
    poolCnt = 0;
    root = myAlloc();
}
 
void insert(int buffer_size, char *buf) {
    root->Insert(buf);
}
 
int query(int buffer_size, char *buf) {
    return root->Find(buf);
}