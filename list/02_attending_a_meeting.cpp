#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node node[50001];

int nodeCnt;
Node* head;
Node h;
Node* tail;
Node t;

void init(){
    nodeCnt = 0;
    head = &h;
    tail = &t;
    head->next = tail;
    tail->next = nullptr;
}

void makeNode(int n){
    for(int i = 1; i <= n; i++){
        node[i].data = i;
        node[i].next = nullptr;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	// freopen("sample_input.txt", "r", stdin);
	cin>>T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
    int n, m, x;
    int s, e, t;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> m >> x;

        int** matrix = new int*[n + 1];
        for(int i = 1; i <= n; i++){
            matrix[i] = new int[n + 1];
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j){
                    matrix[i][j] = 0;
                }
                else{
                    matrix[i][j] = 1000;
                }
            }
        }

        for(int i = 0; i < m; i++){
            cin >> s >> e >> t;
            matrix[s][e] = t;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                for(int k = 1; k <= n; k++){
                    if(j == k){
                        continue;
                    }
                    matrix[j][k] = (matrix[j][k] < matrix[j][i] + matrix[i][k]) ? matrix[j][k] : matrix[j][i] + matrix[i][k];
                }
            }
        }

        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= n; j++){
        //         cout << matrix[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }

        int maxvalue = 0;
        for(int i = 1; i<=n; i++){
            int tmp = matrix[i][x] + matrix[x][i];
            if(tmp > maxvalue){
                maxvalue = tmp;
            }
        }
        cout << '#' << test_case << ' ' << maxvalue << '\n';
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}