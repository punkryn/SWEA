#include <iostream>
using namespace std;

#define MOD 100000

int dp[101][101][2][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int w, h;
    cin >> w >>h;

    for(int i = 2; i <= h; i++){
        dp[i][1][0][0] = 1;
    }

    for(int i = 2; i <= w; i++){
        dp[1][i][0][1] = 1;
    }

    for(int i = 2; i <= h; i++){
        for(int j = 2; j <= w; j++){
            dp[i][j][0][0] = (dp[i-1][j][0][0] + dp[i-1][j][1][0]) % MOD;
            dp[i][j][0][1] = (dp[i][j-1][0][1] + dp[i][j-1][1][1]) % MOD;
            dp[i][j][1][0] = dp[i-1][j][0][1] % MOD;
            dp[i][j][1][1] = dp[i][j-1][0][0] % MOD;
        }
    }

    long long ans = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ans += dp[h][w][i][j];
        }
    }

    cout << ans % MOD << '\n';

    return 0;
}