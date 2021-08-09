#include <iostream>
using namespace std;

#define ALPHABETS_CNT 26
#define MAXN 10000

struct Trie;
Trie* myAlloc();
int order;

struct Trie{
    Trie* children_[ALPHABETS_CNT];
    int isEnd;

    void add(const char* word){
        if(*word != 0){
            if(children_[*word - 'a'] == nullptr) children_[*word - 'a'] = myAlloc();
            if(*(word + 1) == 0){
                isEnd = order++;
            }
            //cout << word << isEnd << '\n';
            children_[*word - 'a']->add(word + 1);
        }
    }

    Trie* get(const char* word){
        if(*(word + 1) == 0){
            cout << word << isEnd << '\n';
            if(isEnd == -1){   
                return nullptr;
            }
        }
        if(*word != 0){
            
            //cout << word << isEnd << '\n';
            if(children_[*word - 'a'] != nullptr) return children_[*word - 'a']->get(word + 1);
            return nullptr;
        }
        return this;
    }

    void clear(){
        isEnd = -1;
        for(int i = 0; i < ALPHABETS_CNT; i++){
            children_[i] = nullptr;
        }
    }
};

Trie node[MAXN];
int nodeCnt = 0;

Trie* myAlloc(){
    Trie* ret = &node[nodeCnt++];
    ret->clear();
    return ret;
}

void go(Trie* node){
    for(int i = 0; i < ALPHABETS_CNT; i++){
        if(node->children_[i] != nullptr){
            cout << node->isEnd << ' ' << i << ' ';
            go(node->children_[i]);
        }
        // cout << '\n';
    }
}

int main(){
    nodeCnt = 0;
    Trie* root = myAlloc();

    root->add("hello");
    root->add("hi");
    root->add("high");
    root->add("goodnight");

    go(root);
    cout << '\n';

    string answer = root->get("goodbye") ? "exist" : "not exist";
    cout << answer << '\n';

    answer = root->get("high") ? "exist" : "not exist";
    cout << answer << '\n';

    answer = root->get("he") ? "exist" : "not exist";
    cout << answer << endl;
}

// a b c d e f g h i j k  l  m  n  o
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

