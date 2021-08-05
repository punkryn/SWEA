#include<iostream>

using namespace std;

#define MAX 1000001

int heap[MAX];
int heapSize;

void init(){
    heapSize = 1;
}

void heapPush(int value){
    int cur = heapSize;
    heap[heapSize++] = value;

    while(cur > 1 && heap[cur] > heap[cur / 2]){
        int tmp = heap[cur];
        heap[cur] = heap[cur / 2];
        heap[cur / 2] = tmp;
        cur /= 2;
    }
    // int cur = heapSize;
    // heap[heapSize++] = value;
    // while(heapSize > 1 && heap[cur] > heap[cur / 2]){
    //     int tmp = heap[cur];
    //     heap[cur] = heap[cur / 2];
    //     heap[cur/2] = tmp;
    //     cur /= 2;
    // }
}

int heapPop(){
    if(heapSize <= 1){
        return -1;
    }

    int value = heap[1];
    heap[1] = heap[--heapSize];

    int cur = 1;
    while(cur * 2 < heapSize){
        int child;
        if(cur * 2 + 1 == heapSize){
            child = cur * 2;
        }
        else{
            child = heap[cur * 2] > heap[cur * 2 + 1] ? cur * 2 : cur * 2 + 1;
        }

        if (heap[cur] > heap[child]){
            break;
        }

        int tmp = heap[cur];
        heap[cur] = heap[child];
        heap[child] = tmp;
        cur = child;
    }

    return value;
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        cout << '#' << test_case << ' ';
        int n, op, value;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> op;
            // for(int j = 0; j < 10; j++){
            //     cout << heap[j] << ' ';
            // }
            // cout << "heap: " << heap[0] << '\n';
            // cout << '\n';
            if(op == 1){
                cin >> value;
                heapPush(value);
            }
            else if(op == 2){
                cout <<heapPop() << ' ';
            }
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}