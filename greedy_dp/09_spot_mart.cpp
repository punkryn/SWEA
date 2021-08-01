#include<iostream>

using namespace std;

int narr[3000];
int marr[100];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n, m;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &narr[i]);

        scanf("%d", &m);
        for(int i = 0; i < m; i++) scanf("%d", &marr[i]);

        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}