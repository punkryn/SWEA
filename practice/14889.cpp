#include <iostream>
using namespace std;

#define MAX 21

int n;
int S[MAX][MAX];
int isUsed[MAX];
// int userPool[MAX];
int minvalue;
int stack[MAX];
int stackPtr;
int tmp[MAX];

int total(int* arr){
    int result = 0;
    for(int i = 0; i < n / 2 - 1; i++){
        for(int j = i + 1; j < n / 2;j ++){
            result += S[arr[i] - 1][arr[j] - 1];
            result += S[arr[j]-1][arr[i]-1];
        }
    }
    return result;
}

void makeTmp(){
    int userPool[MAX] = { 0 };
    int idx = stackPtr;
    while(idx >= 0){
        userPool[stack[idx--]] = 1;
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(userPool[i] == 0){
            tmp[count++] = i;
        }
    }
}

void go(int depth){
    if(depth == n / 2){
        // for(int i = 0; i <= stackPtr; i++){
        //     cout << stack[i] << ' ';
        // }
        // cout << '\n';
        makeTmp();
        minvalue = min(minvalue, abs(total(stack) - total(tmp)));
        return;
    }

    for(int i = 1; i <= n; i++){
        if (stackPtr == -1 || !isUsed[i] && stack[stackPtr] < i){
            isUsed[i] = 1;
            stack[++stackPtr] = i;
            go(depth + 1);
            stackPtr--;
            isUsed[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> S[i][j];
        }
    }
    stackPtr = -1;
    minvalue = int(1e9);
    go(0);
    cout << minvalue << '\n';
}