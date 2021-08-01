#include <iostream>
using namespace std;

int S[100001];
int a[100000];
int b[100000];

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int test_case;
	int T;
	
	cin>>T;
    int n, l;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> l >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
            S[i + 1] = S[i] + (b[i] - a[i]);
        }

        int s = 0;
        int ans = 0;
        for(int e = 0; e < n; e++){
            for(; s <= e && a[s] + l <= b[e]; s++){
                int length = a[s] + l - a[e];
                if(length >= 0){
                    ans = max(ans, S[e] - S[s] + length);
                }
                else{
                    ans = max(ans, S[e] - S[s]);
                }
            }
        }

        if(s < n){
            ans = max(ans, S[n] - S[s]);
        }

        cout << "#" << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}