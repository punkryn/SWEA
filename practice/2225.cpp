#include <iostream>
using namespace std;

#define MAX 200

int n, k;

int dp[MAX + 1][MAX * MAX + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> k;    
    
    for(int i = 0; i <= k; i++) dp[0][i] = 1;
    // dp[0][0] = 1;
    // dp[1][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = i; j < i + k - 1; j++){
            if(i == j){
                dp[i][j] = i + 1;
                continue;
            }
            dp[i][j] = (dp[i-1][j-1] + dp[i][j-1]) % 1000000000;
        }
    }

    // for(int i = 0; i <= n; i++){
    //     for(int j = 0; j < n * k + 1; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][n + k - 2]  << '\n';
}