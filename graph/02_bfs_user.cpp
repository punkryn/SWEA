// #include <iostream>
// using namespace std;

struct Pair{
    int x;
    int y;
    int count;
};

int matrix[10][10];
int len;


Pair q[1000];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs_init(int N, int map[10][10]){
    len = N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix[i][j] = map[i][j];
        }
    }
}


int bfs(int x1, int y1, int x2, int y2){
    int head = 0;
    int tail = 0;
    int visited[10][10] = { 0 };
    q[tail++] = {y1-1, x1-1, 0};
    visited[y1-1][x1-1] = 1;

    if(matrix[y1-1][x1-1] == 1 || matrix[y2-1][x2-1] == 1){
        return -1;
    }

    int x, y, c, nx, ny;
    while (head < tail){
        x = q[head].x;
        y = q[head].y;
        c = q[head].count;
        head++;
        // cout << x << y << c << matrix[x][y] << ' ' << head << ' ' << tail << '\n';
        for(int i = 0; i < 4; i++){
            nx = x + dx[i];
            ny = y + dy[i];

            if(nx == y2-1 && ny == x2-1){
                return c+1;
            }

            if(0 <= ny && ny < len && 0 <= nx && nx < len && !visited[nx][ny]){
                if(matrix[nx][ny] == 0){
                    visited[nx][ny] = 1;
                    q[tail++] = {nx, ny, c+1};
                }
            }
        }
    }

    return -1;
}