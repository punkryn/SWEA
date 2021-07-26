#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAX 100

using namespace std;

int matrix[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

vector<pair<int, int>> total;

bool compare(pair<int, int> a, pair<int, int> b){
    int tmp = a.first * a.second;
    int tmp2 = b.first * b.second;

    if(tmp != tmp2){
        return tmp < tmp2;
    }
    else{
        return a.first < b.first;
    }
}

void find_size(int x, int y){
    int x_ = x;
    int y_ = y;
    int r, c;
    r = c = 0;
    while(matrix[x_][y] != 0){
        r++;
        x_++;
    }
    while(matrix[x][y_] != 0){
        y_++;
        c++;
    }
    
    total.push_back({r, c});
        
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\gns81\\Dropbox\\SWEA\\SWEA\\greedy_dp\\matrix.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d", &n);
        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d ", &matrix[i][j]);
            }
        }

        total.clear();

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         printf("%d ", visited[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        memset(visited, 0, sizeof(visited));

        int x, nx;
        int y, ny;
        int count = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 0 && matrix[i][j] != 0){
                    count++;
                    q.push({i, j});
                    visited[i][j] = count;
                    while(!q.empty()){
                        x = q.front().first;
                        y = q.front().second;
                        //printf("%d %d\n", x, y);

                        //q.erase(q.begin() + 0);
                        q.pop();

                        for(int k = 0; k < 4; k++){
                            nx = x + dx[k];
                            ny = y + dy[k];
                            if(0 <= nx && nx < n && 0<= ny && ny < n){
                                if(visited[nx][ny] == 0){
                                    if(matrix[nx][ny] != 0){
                                       q.push({nx, ny});
                                       visited[nx][ny] = count;
                                    }
                                }
                            }
                        }
                    }
                    
                    find_size(i, j);

                }
            }
        }

        sort(total.begin(), total.end(), compare);

        printf("#%d %d ", test_case, count);

        for(int i = 0; i < count; i++){
            printf("%d %d ", total[i].first, total[i].second);
        }
        printf("\n");

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         printf("%d ", visited[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");
        
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}