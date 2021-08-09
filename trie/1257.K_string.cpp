// https://skud8049.github.io/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/swea-1257/

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

struct suffix{
    string str;
    int idx;
};

bool compare(const suffix& a, const suffix& b){
    return a.str < b.str;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++){
        int k;
        cin >> k;

        string word;
        cin >> word;

        suffix SA[401];
        int LCP[401];

        memset(LCP, 0, sizeof(LCP[0]) * word.size());

        for(int i = 0; i < word.size(); i++){
            SA[i].str = word.substr(i, word.size() - i);
            SA[i].idx = i;
        }

        sort(SA, SA + word.size(), compare);

        for(int i = 1; i < word.size(); i++){
            int min_value = min(SA[i].str.size(), SA[i-1].str.size());
            for(int j = 0; j < min_value; j++){
                if(SA[i].str[j] == SA[i-1].str[j]){
                    LCP[i]++;
                }
                else{
                    break;
                }
            }
        }

        //cout << SA[0].idx << SA[1].idx << SA[2].idx << '\n';

        int sum_value = 0;
        string ans;
        for(int i = 0; i < word.size(); i++){
            int make_value = word.size() - SA[i].idx - LCP[i];

            sum_value += make_value;

            if(sum_value >= k){
                sum_value -= make_value;
                int tmp = k - sum_value + LCP[i];
                ans = SA[i].str.substr(0, tmp);
                break;
            }
        }

        if(ans.size() == 0) cout << "#" << tc << " none\n";
        else cout << "#" << tc << ' ' << ans << '\n';
    }
}