#include<iostream>
#include <cstring>

using namespace std;

char str[1001];
char str2[1001];
int dp[1001][1001];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\gns81\\Dropbox\\SWEA\\SWEA\\greedy_dp\\lcs.txt", "r", stdin);
	cin>>T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
    
    int n, m;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> str >> str2;
        
        n = strlen(str);
        m = strlen(str2);

        //cout << str << '\n' << str2 << '\n';

        

        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }

        for(int i = 0; i <= m; i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j] > dp[i][j-1] ? (dp[i-1][j] > dp[i-1][j-1] + 1 ? dp[i-1][j] : dp[i-1][j-1] + 1) : (dp[i][j-1] > dp[i-1][j-1] + 1 ? dp[i][j-1] : dp[i-1][j-1] + 1);
                }
                else{
                    dp[i][j] = dp[i-1][j] > dp[i][j-1] ? (dp[i-1][j] > dp[i-1][j-1] ? dp[i-1][j] : dp[i-1][j-1] ) : (dp[i][j-1] > dp[i-1][j-1] ? dp[i][j-1] : dp[i-1][j-1]);
                }
            }
        }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");


        cout << '#' << test_case << ' ' << dp[n][m] << '\n';
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}