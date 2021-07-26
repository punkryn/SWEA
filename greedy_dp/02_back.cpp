#include<iostream>
#include <algorithm>

using namespace std;

//int room[400];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\gns81\\Dropbox\\SWEA\\SWEA\\greedy_dp\\back.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;

        // for(int i = 0; i < n; i++){
        //     room[i] = 0;
        // }
        int room[201] = { 0 };

        int a, b;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            if(a > b){
                a ^= b;
                b ^= a;
                a ^= b;
            }
            
            a = (a + 1) / 2;
            b = (b + 1) / 2;
            //printf("%d %d\n", a, b);
            for(int j = a; j <= b; j++){
                room[j] += 1;
            }
        }
        
        // for(int i = 0; i < n; i++){
        //     printf("%d ", room[i]);
        // }
        // printf("\n");

        int maxvalue = 0;
        for(int i = 0; i <= 201; i++){
            if(room[i] > maxvalue){
                maxvalue = room[i];
            }
        }
        
        cout << '#' << test_case << ' ' << maxvalue << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}