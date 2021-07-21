// g++ double_linked_list.cpp UserCode2.cpp -o UserCode2
#define MAX_NODE 10000
//#include <stdio.h>
struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;
Node tail;
Node h;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    //printf("init\n");
    head = &h;
    head->next = &tail;
    
    head->prev = nullptr;
    tail.prev = head;
    tail.next = nullptr;
}

void addNode2Head(int data) 
{
    Node* tmp = getNode(data);
    tmp->next = head->next;
    head->next = tmp;
    tmp->prev = head;
    tmp->next->prev = tmp;
}

void addNode2Tail(int data) 
{
    Node* tmp = getNode(data);
    Node* nxt = head;

    while(nxt->next->next != nullptr){
        nxt = nxt -> next;
    }
    tmp->prev = nxt;
    tmp->next = nxt->next;
    nxt->next = tmp;
    tmp->next->prev = tmp;
}

void addNode2Num(int data, int num) 
{
    Node* tmp = getNode(data);
    Node* nxt= head;

    for(int i = 1; i < num; i++){
        nxt = nxt->next;
    }
    tmp->prev = nxt;
    tmp->next = nxt->next;
    nxt->next->prev = tmp;
    nxt->next = tmp;
}

int findNode(int data) 
{
    Node* nxt = head;
    int idx = 0;
    while(nxt->next->next != nullptr){
        if(nxt->next->data == data){
            idx++;
            return idx;
        }
        nxt = nxt->next;
        idx++;
    }
    return idx;
}

void removeNode(int data) 
{
    Node* nxt = head;
    while(nxt->next->next != nullptr){
        if(nxt->next->data == data){
            nxt->next = nxt->next->next;
            nxt->next->prev = nxt;
            break;
        }
        nxt = nxt->next;
    }
}

int getList(int output[MAX_NODE]) 
{
    Node* nxt = head;
    int idx = 0;
    while(nxt->next->next != nullptr){
        output[idx++] = nxt->next->data;
        nxt = nxt->next;
    }
    return idx;
}

int getReversedList(int output[MAX_NODE]) 
{
    Node* pre = &tail;
    int idx = 0;
    while(pre->prev->prev != nullptr){
        output[idx++] = pre->prev->data;
        pre = pre->prev;
    }
    return idx;
}