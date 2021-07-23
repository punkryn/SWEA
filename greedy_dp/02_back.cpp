#include<iostream>

using namespace std;

struct Room{
    int a;
    int b;
};

Room room[401];
int couple[401][2];

int check(Room f, Room s){
    int bits = 0;
    if((f.a & 1) == 1){
        f.a += 1;
    }
    if((f.b & 1) == 1){
        f.b += 1;
    }
    if((s.a & 1) == 1){
        s.a += 1;
    }
    if((s.b & 1) == 1){
        s.b += 1;
    }
    //cout << f.a << f.b << s.a << f.b << endl;
    if((f.a <= s.a && s.a <= f.b) && f.b <= s.b ){
        bits |= 0b1000;
    }

    else if((f.a <= s.b && s.b <= f.b) && s.a <= f.a){
        bits |= 0b0100;
    }

    else if(f.a <= s.a && s.b <= f.b){
        bits |= 0b0010;
    }

    else if(s.a <= f.a && f.b <= s.b){
        bits |= 0b0001;
    }

    return bits;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\나\\Dropbox\\SWEA\\SWEA\\greedy_dp\\back.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        int a, b;
        for(int i = 0; i < n; i++){
            Room tmp;
            cin >> a >> b;
            if(a < b){
                tmp.a = a;
                tmp.b = b;
            }
            else{
                tmp.a = b;
                tmp.b = a;
            }
            room[i] = tmp;
        }
        
        for(int i = 0; i < n; i++){
            couple[i][0] = 1;
            couple[i][1] = 1;
        }
        // fill(couple, couple+n+1, 1);
        //cout << couple[n] << couple[n + 1] << endl;

        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(i == j) continue;
                int checkbits = check(room[i], room[j]);
                //cout << checkbits << endl;
                if((checkbits & 0b1000) == 0b1000){
                    //cout << "yes" << '\n';
                    // couple[i][0] += 1;
                    couple[i][1] += 1;
                    couple[j][0] += 1;
                    
                }
                else if((checkbits & 0b0100) == 0b0100){
                    couple[i][0] += 1;
                    // couple[i][1] += 1;
                    couple[j][1] += 1;
                }

                else if((checkbits & 0b0010) == 0b0010){
                    couple[i][0]++;
                    couple[i][1]++;
                    couple[j][0]++;
                    couple[j][1]++;
                }

                else if((checkbits & 0b0001) == 0b0001){
                    couple[i][0]++;
                    couple[i][1]++;
                    couple[j][0]++;
                    couple[j][1]++;
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     cout << couple[i][0];
        //     cout << couple[i][1] << ' ';
        // }
        // cout << '\n';

        int maxvalue = 0;
        for(int i = 0; i < n; i++){
            if(couple[i][0] > maxvalue) maxvalue = couple[i][0];
            if(couple[i][1] > maxvalue) maxvalue = couple[i][1];
        }

        cout << '#' << test_case << ' ' << maxvalue << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}