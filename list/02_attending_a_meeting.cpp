#include<iostream>

#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Node{
    int data;
    int num;
    Node* next;
    Node* prev;
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
    head->data = 0;
    head->next = tail;
    head->prev = nullptr;
    tail->data = INF;
    tail->next = nullptr;
    tail->prev = head;
}

Node* getNode(int data, int num){
    node[nodeCnt].data = data;
    node[nodeCnt].num = num;
    node[nodeCnt].next = nullptr;
    node[nodeCnt].prev = nullptr;
    return &node[nodeCnt++];
}

Node* popleft(){
    Node* tmp = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    return tmp;
}

void insert(int data, int num){
    Node* tmp = getNode(data, num);
    Node* nxt = head;
    
    while(nxt->next->next != nullptr){
        if(nxt->next->data > data){
            break;
        }
        nxt = nxt->next;
    }

    tmp->next = nxt->next;
    tmp->prev = nxt;
    nxt->next->prev = tmp;
    nxt->next = tmp;
}

// void add2head(int data){
//     Node* tmp = getNode(data);
//     tmp->next = head->next;
//     tmp->prev = head;
//     head->next->prev = tmp;
//     head->next = tmp;
// }

// void add2tail(int data){
//     Node* tmp = getNode(data);
//     tmp->next = tail;
//     tmp->prev = tail->prev;
//     tail->prev->next = tmp;
//     tail->prev = tmp;
// }



int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("C:\\Users\\나\\Dropbox\\SWEA\\SWEA\\list\\meeting.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n, m, x;
    int s, e, t;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        cin >> n >> m >> x;
        
        vector<pair<int, int>> arr[n + 1];
        vector<pair<int, int>> arr2[n + 1];

        for(int i = 0; i < m; i++){
            cin >> s >> e >> t;
            arr[s].push_back({e, t});
            arr2[e].push_back({s, t});
        }
        
        int distance[n + 1];
        fill(distance, distance+n+1, INF);
        
        // priority_queue<pair<int, int>> q;

        // q.push({0, x});

        Node* q = head;

        distance[x] = 0;

        while(!q.empty()){
            // int cost =-q.top().first;
            // int now = q.top().second;
            // //cout << distance[1] << '\n';
            // q.pop();

            

            for(int i = 0; i < arr[now].size(); i++){
                int next = arr[now][i].first;
                int nextcost = arr[now][i].second;

                if(distance[next] > distance[now] + nextcost){
                    distance[next] = distance[now] + nextcost;
                    q.push({-distance[next], next});
                }
            }
        }

        int distance2[n + 1];
        fill(distance2, distance2+n+1, INF);

        priority_queue<pair<int, int>> q2;
        
        q2.push({0, x});
        distance2[x] = 0;

        while(!q2.empty()){
            int cost =-q2.top().first;
            int now = q2.top().second;

            q2.pop();

            for(int i = 0; i < arr2[now].size(); i++){
                int next = arr2[now][i].first;
                int nextcost = arr2[now][i].second;

                if(distance2[next] > distance2[now] + nextcost){
                    distance2[next] = distance2[now] + nextcost;
                    q2.push({-distance2[next], next});
                }
            }
        }
        
        int maxvalue = 0;
        for(int i = 1; i <= n; i++){
            if(maxvalue < distance[i] + distance2[i]){
                maxvalue = distance[i] + distance2[i];
            }
        }
        
        cout << '#' << test_case << ' ' << maxvalue << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}