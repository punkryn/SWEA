#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 100000
string N[MAX];
string M[MAX];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++){
            cin >> N[i];
        }

        for(int i = 0; i < m; i++){
            cin >> M[i];
        }

        sort(N, N + n);
        sort(M, M + m);

        int nd,  md;
        nd = md = 0;
        int ans = 0;
        while(nd < n && md < m){
            if(N[nd] == M[md]){
                ans++;
                nd++;
                md++;
            }
            else if(N[nd] < M[md]){
                nd++;
            }
            else{
                md++;
            }
        }

        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}