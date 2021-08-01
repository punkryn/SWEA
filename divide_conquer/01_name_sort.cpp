#include<iostream>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX 20000
#define len 50

char name[MAX][len];

using namespace std;

void qsort(int left, int right){
    
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\gns81\\Dropbox\\SWEA\\SWEA\\divide_conquer\\name.txt", "r", stdin);
	cin>>T;
	
    int n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d", &n);
        // for(int i = 0; i < n; i++) scanf("%s", &name[i]);
        for(int i = 0; i < n; i++) 

        for(int i = 0; i < n; i++) printf("%s ", name[i]);

        

        for(int i = 0; i < n; i++) printf("%s ", name[i]);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}