#include<iostream>

using namespace std;

struct Item{
    int v;
    int c;
};

Item item[101];
int dp[101][101];

int main(int argc, char** argv)
{
	int test_case;
	int T;
    freopen("C:\\Users\\나\\Dropbox\\SWEA\\SWEA\\greedy_dp\\knapsack.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n, k;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n>> k;
        for(int i = 0; i < n; i++){
            Item tmp;
            cin >> tmp.v >> tmp.c;
            item[i] = tmp;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                if(item[i-1].v > j){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] > dp[i-1][j - item[i-1].v] + item[i-1].c ? dp[i-1][j] : dp[i-1][j - item[i-1].v] + item[i-1].c;
                }
            }
        }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= k; j++){
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        cout << '#' << test_case << ' '<< dp[n][k] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}