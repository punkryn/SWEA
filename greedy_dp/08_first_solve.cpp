#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\gns81\\Dropbox\\SWEA\\SWEA\\greedy_dp\\s_input.txt", "r", stdin);
	cin>>T;
	
    int n;
    int answer;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = 0;
        scanf("%d", &n);

        vector<pair<int, int>> v;

        int s, f;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &s, &f);

            
        }
        printf("#%d %d\n", test_case, answer);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}