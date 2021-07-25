#include<iostream>

using namespace std;

int result;
int n;
int alist[6];
int size_;

int makeNum(){
    int count = 1;
    int result = 0;
    for(int i = size_ - 1; i >= 0; i--){
        result += (alist[i] * count);
        count *= 10;
    }
    
    return result;
}

void change(int depth, int now){
    //printf("%d %d\n", depth, now);
    if(depth == 0){
        int tmp = makeNum();
        if(result < tmp){
            result = tmp;
        }
        return;
    }

    for(int i = now; i < size_; i++){
        for(int j = i + 1; j < size_; j++){
            if(alist[i] < alist[j]){
                alist[i] ^= alist[j];
                alist[j] ^= alist[i];
                alist[i] ^= alist[j];

                change(depth - 1, i);

                alist[i] ^= alist[j];
                alist[j] ^= alist[i];
                alist[i] ^= alist[j];
            }
        }
    }

    if(depth % 2 == 0){
        int tmp = makeNum();
        if(result < tmp){
            result = tmp;
        }
    }
    else{
        for(int i = 0; i < size_; i++){
            for(int j = i + 1; j < size_; j++){
                alist[i] ^= alist[j];
                alist[j] ^= alist[i];
                alist[i] ^= alist[j];

                int tmp = makeNum();
                if(result < tmp){
                    result = tmp;
                }

                alist[i] ^= alist[j];
                alist[j] ^= alist[i];
                alist[i] ^= alist[j];
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\gns81\\Dropbox\\SWEA\\SWEA\\greedy_dp\\prize.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int a;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        result = 0;
		cin >> a >> n;

        for(int j = 0; j < 6; j++){
            alist[j] = 0;
        }

        size_ = 0;
        int b = a;
        while(b){
            size_++;
            b /= 10;
        }
        
        int i = size_ - 1;
        while(a){
            alist[i--] = a % 10;
            a /= 10;
        }
        // for(int j = 0; j < 6; j++){
        //     cout << alist[j];
        // }
        // cout << '\n';

        change(n, 0);

        cout << '#' << test_case << ' '<< result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}