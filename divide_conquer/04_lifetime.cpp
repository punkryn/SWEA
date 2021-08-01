#include<iostream>

using namespace std;

#define MAX 200001
int W[MAX];
int S[MAX];
int n, k;

bool check(int p){
    int i, now = 1, cont = 0;
    for(i = 1; i <= n; ++i){
        if(W[i] <= p)
            cont++;
        else
            cont = 0;
        
        if(cont == S[now]){
            cont = 0;
            if(++now > k)
                break;
        }
    }
    cout << now << ' ' << k << '\n';
    return now > k;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> W[i];
        for(int i = 1; i <= k; i++) cin >> S[i];

        int s = 1;
        int e = MAX;
        int m;
        while(s < e){
            m = (s + e) / 2;
            if(check(m))
                e = m;
            else
                s = m + 1;
        }
        cout << '#' << test_case << ' ' << s << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}