#include<iostream>
#include <string>
using namespace std;

#define MAX 3000

struct Pair{
    int id;
    int left;
    int right;
}tree[MAX];

char oper[MAX];
float stack[MAX];
int stackPtr;

void init(){
    stackPtr = -1;
    for(register int i = 0; i < MAX; i++){
        tree[i].left = 0;
        tree[i].right = 0;
        oper[i] = '\0';
    }
}

void makeNum(int& v, char& op, int& left, int& right, string str, int& node){
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
                }
                else{
                    node = stoi(tmp);
                    return;
                }
            }
            else if(cnt == 2) left = stoi(tmp);
            else if(cnt == 3) right = stoi(tmp);
            tmp = "";
            cnt++;
        }
    }
}

void traverse2(int cur){
    if(tree[cur].left != 0) traverse2(tree[cur].left);
    if(tree[cur].right != 0) traverse2(tree[cur].right);
    if(tree[cur].id > 0){
        stack[++stackPtr] = float(tree[cur].id);
    } 
    else if(tree[cur].id == -1){
        float a = stack[stackPtr--];
        float b = stack[stackPtr--];
        if(oper[cur] == '+'){
            stack[++stackPtr] = (b + a);
        }
        else if(oper[cur] == '-'){
            stack[++stackPtr] = (b - a);
        }
        else if(oper[cur] == '*'){
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
	int T = 10;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        cin.ignore(1, '\n');
        string str;
        int v, left, right, node;
        char op;
        init();
        for(int i = 0; i < n; i++){
            left = 0; right = 0; op = '\0'; node = 0;
            getline(cin, str);
            makeNum(v, op, left, right, str, node);
            if(op == '\0') tree[v].id = node;
            else{
                tree[v].id = -1;
                oper[v] = op;
                tree[v].left = left;
                tree[v].right = right;
            }
        }
        
        traverse2(1);
        cout << "#" << test_case << ' ' << int(stack[0]) << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}