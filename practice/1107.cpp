#include <iostream>
#include <string>

using namespace std;

#define MAX 1000001

int broken[10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    if (m > 0){
        int tmp;
        for(int i = 0; i < m; i++){
            cin >> tmp;
            broken[tmp] = 1;
        }
    }

    int cnt = abs(100 - n);
    for(int i = 0; i < MAX; i++){
        string tmp = to_string(i);
        
        for(int j = 0; j < tmp.size(); j++){
            if(broken[int(tmp[j]) - int('0')] == 1) break;
            else if(j == tmp.size() - 1){
                cnt = min(cnt, int(tmp.size() + abs(n - i)));
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}