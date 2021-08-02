// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 3 7
// 3 8
// 4 9
// 5 10
// 5 11
// 11 14
// 8 12
// 8 13

#include <iostream>
using namespace std;

#define MAX_POOL 10000

struct NodeList{
    int id;
    NodeList* prev;
}NodePool[MAX_POOL];

struct TreeNode{
    int parent;
    NodeList* child;
}treeNode[MAX_POOL];

int memPoolCnt;

void init(){
    memPoolCnt = 0;
    for(register int i = 0; i < MAX_POOL; i++){
        treeNode[i].parent = -1;
        treeNode[i].child = nullptr;
    }
}

int findRoot(int n){
    while(treeNode[n].parent != -1){
        n = treeNode[n].parent;
    }
    return n;
}

void traverse(int cur){
    cout << cur << ' ';
    for(NodeList* l = treeNode[cur].child; l != nullptr; l = l->prev){
        traverse(l->id);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    int parent, child;
    NodeList* list;
    for(int i = 0; i < 13; i++){
        cin >> parent >> child;
        treeNode[child].parent = parent;
        list = &NodePool[memPoolCnt++];
        list->id = child;
        list->prev = treeNode[parent].child;
        treeNode[parent].child = list;
    }

    cout << findRoot(14) << '\n';
    traverse(1);

    return 0;
}