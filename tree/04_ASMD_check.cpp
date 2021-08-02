// 9
// 1 * 2 3
// 2 + 4 5
// 3 - 6 7
// 4 / 8 9
// 5 2
// 6 6
// 7 4
// 8 8
// 9 7

#include<iostream>
#include <string>
using namespace std;

#define MAX 1000

struct Pair{
    int id;
    char op;
}tree[MAX];

float stack[MAX];
int stackPtr;
bool flag;

void makeNum(int& v, char& op, string str, int& node){
    string tmp = "";
    int cnt = 0;
    for(int i = 0; i <= str.size(); i++){
        if(str[i] != ' ' && str[i] != '\0'){
            tmp += str[i];
        }
        else if(str[i] == ' ' || str[i] == '\0'){
            //cout << "cnt: " << cnt << '\n';
            if(cnt == 0) v = stoi(tmp);
            else if(cnt == 1){
                if(tmp[0] == '-' || tmp[0] == '+' || tmp[0] == '*' || tmp[0] == '/'){
                    op = tmp[0];
                    return;
                }
                else{
                    node = stoi(tmp);
                    return;
                }
            }
            tmp = "";
            cnt++;
        }
    }
}

void init(){
    stackPtr = -1;
    flag = true;
    for(register int i = 0; i < MAX; i++){
        tree[i].id = 0;
        tree[i].op = '\0';
    }
}

void traverse(int cur){
    if(tree[cur * 2].id != 0) traverse(cur * 2);
    if(tree[cur * 2 + 1].id != 0) traverse(cur * 2 + 1);

    if(tree[cur].id > 0) stack[++stackPtr] = float(tree[cur].id);
    else if(tree[cur].id == -1){
        if(stackPtr == -1) flag = false;
        float a = stack[stackPtr--];
        if(stackPtr == -1) flag = false;
        float b = stack[stackPtr--];
        if(tree[cur].op == '+'){
            stack[++stackPtr] = (b + a);
        }
        else if(tree[cur].op == '-'){
            stack[++stackPtr] = (b - a);
        }
        else if(tree[cur].op == '*'){
            stack[++stackPtr] = (b * a);
        }
        else{
            float tmp = b / a;
            stack[++stackPtr] = tmp;
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int test_case;
	int T = 1;
	//freopen("input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        cin.ignore(1, '\n');

        string str;
        int v, node;
        char op;
        init();
        for(int i = 0; i < n; i++){
            op = '\0'; node = 0;
            getline(cin, str);
            makeNum(v, op, str, node);
            if(op == '\0') tree[v].id = node;
            else{
                tree[v].id = -1;
                tree[v].op = op;
            }
        }

        traverse(1);
        if(stackPtr != 0) flag = false;

        cout << "#" << test_case << ' ' << flag << '\n';

        // for(int i = 0; i < 20; i++){
        //     cout << tree[i].op << ' ';
        // }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}