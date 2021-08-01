#include <iostream>
#define N 101
#define COL 100001
using namespace std;

int weight[N];
int value[N];
int dp[N][COL];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> weight[i] >> value[i];
    }

    int w, v;
    for(int i = 1; i <= n; i++){
        w = weight[i-1]; v = value[i-1];
        for(int j = 1; j <= k; j++){
            if(w > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
        }
    }
    cout << dp[n][k];

    return 0;
}