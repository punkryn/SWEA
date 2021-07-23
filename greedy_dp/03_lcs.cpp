#include<iostream>
#include <cstring>

using namespace std;

char str[1001];
char str2[1001];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\나\\Dropbox\\SWEA\\SWEA\\greedy_dp\\lcs.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int idx, idx2;
    int result;
    int ans;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> str >> str2;
        ans = 0;
        idx = 0;
        idx2 = 0;
        result = 0;
        for(int k = 0; k < strlen(str); k++){
            for(int i = k; i < strlen(str); i++){
                idx2 = idx;
                while(idx2 < strlen(str2)){
                    if(str2[idx2] == str[i]){
                        result += 1;
                        idx = idx2 + 1;
                        break;
                    }
                    idx2++;
                }
            }

            if(ans < result){
                ans = result;
            }

            result = 0;
            idx2 = 0;
            idx = 0;
        }

        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}