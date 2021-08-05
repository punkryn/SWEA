#include<iostream>

using namespace std;

#define MAX 101
#define INF 10000000

struct Pair{
    int cost;
    int x;
    int y;
};

Pair heap[10000];
int heapSize;
int distances[MAX][MAX];
char map[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n;

void init(){
    heapSize = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            distances[i][j] = INF;
        }
    }
}

void heapPush(Pair value){
    int cur = heapSize;
    heap[heapSize++] = value;

    while(heapSize > 1 && heap[cur].cost < heap[cur / 2].cost){
        Pair tmp = heap[cur];
        heap[cur] = heap[cur / 2];
        heap[cur/2] = tmp;
        cur /= 2;
    }
}

Pair heapPop(){
    Pair value = heap[1];
    heap[1] = heap[--heapSize];
    int cur = 1;
    while(cur * 2 < heapSize){
        int child;
        if(cur * 2 + 1 == heapSize){
            child = cur * 2;
        }
        else{
            child = heap[cur * 2].cost < heap[cur * 2 + 1].cost ? cur * 2 : cur * 2 + 1;
        }
        
        if(heap[cur].cost < heap[child].cost){
            break;
        }

        Pair tmp = heap[cur];
        heap[cur] = heap[child];
        heap[child] = tmp;
        cur = child;
    }

    return value;
}

void dijkstra(){
    heapPush({0, 0, 0});
    distances[0][0] = 0;

    while(heapSize > 1){
        Pair now = heapPop();
        int x = now.x;
        int y = now.y;
        int dist = now.cost;

        if(distances[x][y] < dist){
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < n){
                int cost = dist + int(map[nx][ny]) - int('0');
                // cout << "cost: " << cost << nx << ny << '\n';
                if(cost < distances[nx][ny]){
                    distances[nx][ny] = cost;
                    heapPush({cost, nx, ny});
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{  
        cin >> n;
        init();
        for(int i = 0; i < n; i++){
            cin >> map[i];
        }
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++)
        //         cout << distances[i] << ' ';
        //     cout << '\n';
        // }

        dijkstra();
        cout << '#' << test_case << ' ' << distances[n-1][n-1] << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}