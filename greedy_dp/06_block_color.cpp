// ��� ���� �Ķ� ���� �״� ����� ��
// ��� ���� �����ؼ� ���� �� ������ �Ķ� ���� ������ ���� �����ؼ� ���� �� ����.
// �� �� 

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