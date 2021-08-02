#include<iostream>
#include <string>
using namespace std;

#define MAX_POOL 1010

int tree[MAX_POOL];
char word[MAX_POOL];

void init(){
    for(register int i = 0; i < MAX_POOL; i++){
        tree[i] = 0;
        word[i] = '\0';
    }
}

void makeNum(int* v, char* alp, int* left, int* right, string str){
    string tmp = "";
    int cnt = 0;
    for(int i = 0; i <= str.size(); i++){
        if(cnt == 1){
            // cout << "i: " << i << str[i] << '\n';
            *alp = str[i];
            cnt++;
            continue;
        }

        if(str[i] != ' ' && str[i] != '\0'){
            tmp += str[i];
        }
        else if(str[i] == ' ' || str[i] == '\0'){
            //cout << "cnt: " << cnt << '\n';
            if(cnt == 0) *v = stoi(tmp);
            else if(cnt == 3) *left = stoi(tmp);
            else if(cnt == 4) *right = stoi(tmp);
            tmp = "";
            cnt++;
        }
    }
}

void traverse(int cur){
    if(tree[cur*2] != 0) traverse(cur*2);
    cout << word[cur];
    if(tree[cur*2 + 1] != 0) traverse(cur*2 + 1);
}

int findLeftNode(int cur){
    while(tree[cur] != 0){
        cur *= 2;
    }
    return cur / 2;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	int test_case;
	int T = 10;
	
	//freopen("input.txt", "r", stdin);
	// cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();

        int n;
        cin >> n;
        int v, left, right;
        char alphabet;
        string str;
        cin.ignore(1, '\n');
        for(int i = 0; i < n; i++){
            left = 0; right = 0;
            getline(cin, str);
            makeNum(&v, &alphabet, &left, &right, str);
            // cout << ' ' << v << ' ' << alphabet << ' ' << left << right << '\n';
            tree[v] = v;
            word[v] = alphabet;
            if(left != 0) tree[left] = left;
            if(right != 0) tree[right] = right;
        }
        cout << "#" << test_case << ' ';
        traverse(1);
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}