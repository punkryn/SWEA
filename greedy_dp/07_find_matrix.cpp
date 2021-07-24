#include<iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\나\\Dropbox\\SWEA\\SWEA\\greedy_dp\\matrix.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d", &n);
        int matrix[n][n];
        int visited[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d ", &matrix[i][j]);
            }
        }

        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         printf("%d ", visited[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = 0;                
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int x, nx;
        int y, ny;
        int count = 0;
        vector<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == 0 && matrix[i][j] != 0){
                    count++;
                    q.push_back({i, j});
                    while(!q.empty()){
                        x = q[0].first;
                        y = q[0].second;
                        //printf("%d %d\n", x, y);

                        q.erase(q.begin() + 0);

                        visited[x][y] = count;

                        for(int k = 0; k < 4; k++){
                            nx = x + dx[k];
                            ny = y + dy[k];
                            if(0 <= nx && nx < n && 0<= ny && ny < n){
                                if(visited[nx][ny] == 0){
                                    if(matrix[nx][ny] != 0){
                                       q.push_back({nx, ny});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        int arr[count] = {0};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
            }
        }

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