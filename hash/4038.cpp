// KMP
// 1                                  
// ABABABABBABABABABC
// ABABABABC
#include<iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 100001

int pi[MAX];

void getPi(string p){
    int m = p.size();
    int j = 0;
    
    for(int i = 1; i < m; i++){
        while(j > 0 && p[i] != p[j]){
            j = pi[j-1];
        }

        if(p[i] == p[j]){
            pi[i] = ++j;
        }
    }
}


int kmp(string s, string p){
    int ans = 0;
    int n = s.size();
    int m = p.size();
    int j = 0;
    getPi(p);

    for(int i = 0; i < n; i++){
        while(j > 0 && s[i] != p[j]){
            j = pi[j-1];
        }

        if(s[i] == p[j]){
            if(j == m - 1){
                ans++;
                j = pi[j];
            }
            else{
                j++;
            }
        }
    }
    return ans;
}

int main(int argc, char** argv)
{   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string s, p;
        cin >> s >> p;

        for(int i = 0; i < p.size(); i++){
            pi[i] = 0;
        }

        int ans = kmp(s, p);
        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}