// 노란 블럭과 파란 블럭을 쌓는 경우의 수
// 노란 블럭은 연속해서 쌓을 수 있지만 파란 블럭은 동일한 색을 연속해서 쌓을 수 없다.
// 이 때 

#include <iostream>

using namespace std;

int main(){
    int dp[100][2];
    int n = 10;
    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    printf("%d\n", dp[10][0] + dp[10][1]);
}