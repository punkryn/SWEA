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
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
    int n, m;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf("%d", &narr[i]);

        scanf("%d", &m);
        for(int i = 0; i < m; i++) scanf("%d", &marr[i]);

        
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}