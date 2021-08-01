// 2
// 2 1 1406932606
// 33 69
// 3 3 1293799192
// 36 95
// 61 95
// 95 -1

// 1
// 4 4 996984527
// 26 68
// 68 -1
// 7 52
// 52 -1

// 1
// 14 11 460325307
// 68 82
// 55 82
// 82 -1
// 15 -1
// 50 82
// 97 -1
// 6 68
// 22 77
// 77 97
// 57 -1
// 78 -1

// #include <iostream>
// using namespace std;

// struct Node{
//     Node* next;
//     Node* prev;
//     int data;
// };

// Node node[10000];
// int nodeCnt;

// Node* getNode(int data){
//     node[nodeCnt].data = data;
//     node[nodeCnt].next = nullptr;
//     node[nodeCnt].prev = nullptr;
//     return &node[nodeCnt++];
// }

// Node trees[100];
// Node* nxt[100];


// void add2tail(int data, Node* tail, int idx){
//     Node* tmp = getNode(data);
//     tail->next = tmp;
//     nxt[idx] = tmp;
// }


//int tree[100][100];
int stack[10000], top;
int paths[100][2];
int N_;
void dfs_init(int N, int path[100][2])
{
    // nodeCnt = 0;
    N_ = N;
    // for(int i = 0; i < 100; i++){
    //     trees[i].next = nullptr;
    //     nxt[i] = &trees[i];
    // }

    for(int i = 0; i < N - 1; i++){
        //cout << path[i][0] << ' ' << path[i][1] << "tree" << N << '\n';
        //tree[path[i][0]][path[i][1]] = 1;

        paths[i][0] = path[i][0];
        paths[i][1] = path[i][1];

        // add2tail(path[i][1], nxt[path[i][0]], path[i][0]);
        //cout << tree[path[i][0]][path[i][1]] << '\n';
    }
}

int dfs(int n)
{
    bool visited[100] = { false };
    top = -1;
    stack[++top] = n;
    while(top != -1){
        int cur = stack[top--];
        if(cur > n) return cur;

        if(!visited[cur]){
            for(int i = N_ - 2; i >= 0; i--){
                if(!visited[paths[i][1]] && paths[i][0] == cur){
                    stack[++top] = paths[i][1];
                    
                }
            }
        }
    }
    return -1;
}