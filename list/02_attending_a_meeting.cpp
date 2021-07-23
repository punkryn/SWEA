#include<iostream>
#include <cstdio>
//#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Node{
    int a;
    int b;
    Node* prev;
} node[1000002];

struct Pair{
    Node* data;
} user[50001];

Pair user2[50001];

int poolCnt;

// int getSize(Node* data){
//     int count = 0;
//     while(data != nullptr){
//         data = data->prev;
//         count += 1;
//     }
//     return count;
// }

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	// freopen("sample_input.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    int n, m, x;
    int s, e, t;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n >> m >> x;
        poolCnt = 0;
        
        // vector<pair<int, int>> arr[n + 1];
        // vector<pair<int, int>> arr2[n + 1];


        for(int i = 0; i < m; i++){
            //cin >> s >> e >> t;
            scanf("%d %d %d", &s, &e, &t);

            Node* tmp = &node[poolCnt++];
            tmp->a = e;
            tmp->b = t;
            tmp->prev = user[s].data;
            user[s].data = tmp;

            Node* tmp2 = &node[poolCnt++];
            tmp2->a = s;
            tmp2->b = t;
            tmp2->prev = user2[e].data;
            user2[e].data = tmp2;

            // arr[s].push_back({e, t});
            // arr2[e].push_back({s, t});
        }
        
        int distance[n + 1];
        fill(distance, distance+n+1, INF);
        
        priority_queue<pair<int, int>> q;

        q.push({0, x});
        distance[x] = 0;

        while(!q.empty()){
            int cost =-q.top().first;
            int now = q.top().second;
            //cout << distance[1] << '\n';
            q.pop();


            Node* tmpdata = user[now].data;
            while(tmpdata != nullptr){
                int next = tmpdata->a;
                int nextcost = tmpdata->b;

                if(distance[next] > distance[now] + nextcost){
                    distance[next] = distance[now] + nextcost;
                    q.push({-distance[next], next});
                }

                tmpdata = tmpdata->prev;
            }

            // for(int i = 0; i < arr[now].size(); i++){
            //     int next = arr[now][i].first;
            //     int nextcost = arr[now][i].second;

            //     if(distance[next] > distance[now] + nextcost){
            //         distance[next] = distance[now] + nextcost;
            //         q.push({-distance[next], next});
            //     }
            // }
        }

        //poolCnt = 0;

        int distance2[n + 1];
        fill(distance2, distance2+n+1, INF);

        priority_queue<pair<int, int>> q2; 
        
        q2.push({0, x});
        distance2[x] = 0;

        while(!q2.empty()){
            int cost =-q2.top().first;
            int now = q2.top().second;

            //printf("%d %d \n", cost, now);

            q2.pop();

            Node* tmpdata = user2[now].data;
            while(tmpdata != nullptr){
                int next = tmpdata->a;
                int nextcost = tmpdata->b;

                if(distance2[next] > distance2[now] + nextcost){
                    distance2[next] = distance2[now] + nextcost;
                    q2.push({-distance2[next], next});
                }

                tmpdata = tmpdata->prev;
            }

            // for(int i = 0; i < arr2[now].size(); i++){
            //     int next = arr2[now][i].first;
            //     int nextcost = arr2[now][i].second;

            //     if(distance2[next] > distance2[now] + nextcost){
            //         distance2[next] = distance2[now] + nextcost;
            //         q2.push({-distance2[next], next});
            //     }
            // }
        }
        // for(int i = 1; i <= n; i++){
        //     cout << distance2[i] << ' ';
        // }
        // cout << '\n';
        
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