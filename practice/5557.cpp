#include <iostream>
using namespace std;

long long dp[101][21];
int arr[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dp[0][arr[0]] = 1;
    for(int i = 1; i < n - 1; i++){
        for(int j = 0; j <= 20; j++){
            if(dp[i-1][j] > 0){
                int sum_value = arr[i] + j;
                int sub_value = j - arr[i];

                if(sum_value <= 20) dp[i][sum_value] += dp[i-1][j];
                if(sub_value >= 0) dp[i][sub_value] += dp[i-1][j];
            }
        }
    }

    // for(int i = 0; i <= 20; i++){
    //     cout << dp[n-2][i] << ' ';
    // }

    cout << dp[n-2][arr[n-1]] << '\n';
}