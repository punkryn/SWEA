#include <iostream>
using namespace std;

#define MAX_POOL 100000

struct user{
    int uID;
    int income;
};

user heap[MAX_POOL];
int heapSize;

void init()
{
    heapSize = 0;
}

void addUser(int uID, int income) 
{
    //cout << "income: " << uID << '\n';
    user tmp = {uID, income};
    int cur = heapSize;
    heap[heapSize++] = tmp;

    while(cur > 0 && heap[cur].income >= heap[(cur - 1) / 2].income){
        if(heap[cur].income == heap[(cur - 1)/2].income){
            if(heap[cur].uID < heap[(cur-1)/2].uID){
                user temp = heap[cur];
                heap[cur] = heap[(cur-1)/2];
                heap[(cur-1)/2] = temp;
                cur = (cur-1)/2;
            }
        }
        else{
            user temp = heap[cur];
            heap[cur] = heap[(cur-1)/2];
            heap[(cur-1)/2] = temp;
            cur = (cur-1)/2;
        }
    }
}

int getTop10(int result[10]) 
{
    // for(int i = 0; i < 10; i++){
    //     cout << heap[i].uID << ' ';
    // }
    // cout << '\n';

    int count = 0;
    while(0 < heapSize && count < 10){
        // cout << "123\n" << count << heapSize;
        int value = heap[0].uID;
        heap[0] = heap[--heapSize];

        int cur = 0;
        while(cur * 2 + 1 < heapSize){
            int child;
            if(cur * 2 + 2 == heapSize){
                child = cur * 2 + 1;
            }
            else{
                child = heap[cur * 2 + 1].income > heap[cur * 2 + 2].income ? cur * 2 + 1 : cur * 2 + 2;
                if(heap[cur * 2 + 1].income > heap[cur * 2 + 2].income){
                    child = cur * 2 + 1;
                }
                else if (heap[cur * 2 + 1].income < heap[cur * 2 + 2].income){
                    child = cur * 2 + 2;
                }
                else{
                    if(heap[cur * 2 + 1].uID < heap[cur * 2 + 2].uID){
                        child = cur * 2 + 1;
                    }
                    else{
                        child = cur * 2 + 2;
                    }
                }
            }

            if(heap[cur].income > heap[child].income){
                break;
            }

            user temp = heap[cur];
            heap[cur] = heap[child];
            heap[child] = temp;
            cur = child;
        }
        result[count++] = value;

    }
    // for(int i = 0; i < 10; i++){
    //     cout << result[i] << ' ';
    // }
    return count;
}