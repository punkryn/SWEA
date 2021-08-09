#include<iostream>
#include <set>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n, a;
        cin >> n >> a;
        multiset<int> s;
        s.insert(a);
        long long total = 0;
        auto pos = s.begin();
        
        int mid = a;
        for(int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            s.insert(x);
            s.insert(y);

            if(x >= mid && y >= mid){
                pos++;
            }
            else if(x >= mid && y <= mid){

            }
            else if(x <= mid && y >= mid){

            }
            else if(x <= mid && y <= mid){
                pos--;
            }

            total += (*pos);
            total %= 20171109;
            //cout << total << '\n';
            mid = (*pos);
        }
        cout << '#' << test_case << ' ' << total << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}