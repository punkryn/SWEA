// https://blog.uniony.me/swea/4753/

#include <iostream>
#include <string>

using namespace std;

#define MAXN 30000
#define MAXM 30000
#define ACNT 26

struct Trie;
// Trie* myAlloc();

// Trie Node[MAXN * 30];
int nodeCnt;

struct Trie{
    Trie* _children[ACNT];
    int cnt;
    int ans;

    Trie* Alloc(){
        cnt = 0;
        ans = -1;
        for(int i = 0; i < ACNT; i++){
            _children[i] = nullptr;
        }
        return this;
    }
}Node[MAXN * 30];

Trie root;

void add(const char* str){
    Trie* node = &root;
    int ans = 0;
    for(int i = 0; str[i]; i++){
        node->cnt++;
        ans += node->cnt;
        int cur = str[i] - 'a';
        if(!node->_children[cur]) node->_children[cur] = Node[nodeCnt++].Alloc();
        node = node->_children[cur];
    }

    node->cnt++;
    ans += node->cnt;
    node->ans = ans;
    return;
}

int find(const char* str){
    Trie* node = &root;
    int ans = 0;
    bool none = false;
    for(int i = 0; str[i]; i++){
        ans += node->cnt;
        int cur = str[i] - 'a';
        if(!node->_children[cur]){
            none = true;
            break;
        }
        node = node->_children[cur];
    }
    if(none) return ans;
    if(node->ans == -1) return ans + node->cnt;
    return node->ans;
}

// Trie* myAlloc(){
//     Trie* ret = &Node[nodeCnt];
//     ret->clear();
//     return ret;
// }

void init(){
    nodeCnt = 0;
    root.Alloc();
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
        char str[30];
        int n, m;
        cin >> n;
        init();
        for(int i = 0; i < n; i++){
            cin >> str;
            add(str);
        }

        cin >> m;
        long long ans = 0;
        for(int i = 0; i < m; i++){
            cin >> str;
            ans += find(str);
            //cout << ans << '\n';
        }
        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

// // 4+3+2+3=12
// // 2+2+2=6
// // 3+3+2+3=11