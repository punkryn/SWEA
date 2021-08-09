#include<iostream>
#include <cstring>
using namespace std;

#define ACNT 26
#define MAXN 401

struct Trie;
Trie* myAlloc();
int order;
int cnt, k;

struct Trie{
    Trie* _children[ACNT];
    int isEnd;

    void add(const char* word, int idx){
        if(*word != 0){
            if(_children[*word - 'a'] == nullptr) _children[*word - 'a'] = myAlloc();
            if(*(word + 1) == 0) isEnd = idx;
            _children[*word - 'a']->add(word + 1, idx);
        }
    }

    Trie* get(const char* word){
        if(*(word + 1) == 0){
            if(isEnd == -1){
                return nullptr;
            }
        }
        if(*word != 0){
            if(_children[*word - 'a'] != nullptr) return _children[*word - 'a']->get(word + 1);
            return nullptr;
        }
        return this;
    }

    void clear(){
        isEnd = -1;
        for(int i = 0; i < ACNT; i++){
            _children[i] = nullptr;
        }
    }

    
};

Trie node[MAXN];
int nodeCnt;
Trie* myAlloc(){
    Trie* ret = &node[nodeCnt++];
    ret->clear();
    return ret;
}

int ans;
void go(Trie* node){
    if(cnt == k - 1){
        ans = node->isEnd;
        return;
    }

    for(int i = 0; i < ACNT; i++){
        if(node->_children[i] != nullptr){

        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> k;

        char word[400];
        cin >> word;

        order = 0; cnt = 0;
        Trie* root = myAlloc();
        for(int i = 0; i < strlen(word); i++){
            root->add(word + i, i);
        }


	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}