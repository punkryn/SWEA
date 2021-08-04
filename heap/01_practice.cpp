#include <iostream>
using namespace std;

#define MAX 101

int heap[MAX];
int heapSize;

void heapInit(){
    heapSize = 1;
}

int heapPush(int value){
    if(heapSize >= MAX){
        cout << "Queue is full\n";
        return 0;
    }

    int cur = heapSize;
    heap[heapSize++] = value;

    while(cur > 1 && heap[cur] < heap[cur / 2]){
        int tmp = heap[cur];
        heap[cur] = heap[cur / 2];
        heap[cur / 2] = tmp;
        cur /= 2;
    }

    return 1;
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
            child = heap[cur * 2] < heap[cur * 2 + 1] ? cur * 2 : cur * 2 + 1;
        }

        if(heap[cur] < heap[child])
            break;

        int tmp = heap[cur];
        heap[cur] = heap[child];
        heap[child] = tmp;
        cur = child;
    }

    return value;
}

int main(){
    srand(12);
    heapInit();

    for(int i = 0; i < 100; i++){
        // heapPush(rand() % 100 + 1);
        heapPush(i + 1);
    }
    for(int i = 0; i < 100; i++){
        //cout << i << ' ' << heap[i + 1] << '\n';
        cout << i << ' ' << heapPop() << '\n';
    }
    cout << '\n';
    return 0;
}