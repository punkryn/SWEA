#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	//freopen("input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        cout << '#' << test_case << '\n';
        if(n / 50000 > 0){
            while(n / 50000 > 0){
                cout << n / 50000 << ' ';
                n %= 50000;
            }
        }
        else{
            cout << 0 << ' ';
        }
        

        if(n / 10000 > 0){
            while(n / 10000 > 0){
                cout << n / 10000 << ' ';
                n %= 10000;
            }
        }
        else{
            cout << 0 << ' ';
        }

        if(n / 5000 > 0){
            while(n / 5000 > 0){
            cout << n / 5000 << ' ';
            n %= 5000;
        }
        }
        else{
            cout << 0 << ' ';
        }
        
        if(n / 1000 > 0){
            while(n / 1000 > 0){
            cout << n / 1000 << ' ';
            n %= 1000;
        }
        }
        else{
            cout << 0 << ' ';
        }

        if(n / 500 > 0){
            while(n / 500 > 0){
            cout << n / 500 << ' ';
            n %= 500;
        }
        }
        else{
            cout << 0 << ' ';
        }

        if(n / 100 > 0){
            while(n / 100 > 0){
            cout << n / 100 << ' ';
            n %= 100;
        }
        }
        else{
            cout << 0 << ' ';
        }

        if(n / 50 > 0){
            while(n / 50 > 0){
            cout << n / 50 << ' ';
            n %= 50;
        }
        }
        else{
            cout << 0 << ' ';
        }
        
        if(n / 10 > 0){
            while(n / 10 > 0){
            cout << n / 10 << ' ';
            n %= 10;
        }
        }
        else{
            cout << 0 << ' ';
        }

        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}