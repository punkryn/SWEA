// g++ single_linked_list.cpp UserCode.cpp -o UserCode
#define MAX_NODE 10000

//#include <stdio.h>

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node head;
Node tail;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
    //printf("init\n");
    nodeCnt = 0;
    //printf("init2\n");
    //printf("%d\n", nullptr);
    head.next = &tail;
    
    //printf("init3\n");
    tail.next = nullptr;
}

void addNode2Head(int data) 
{
    Node* tmp = getNode(data);
    //printf("tmp %d\n", tmp->data);
    tmp->next = head.next;
    head.next = tmp;
    //printf("headnext %d\n", head.next->data);
}

void addNode2Tail(int data) 
{
    Node* tmp = getNode(data);
    Node* nxt = &head;
    while(nxt->next->next != nullptr){
        nxt = nxt -> next;
    }
    tmp->next = &tail;
    nxt->next = tmp;
}

void addNode2Num(int data, int num) 
{
    int count = 1;
    Node* tmp = getNode(data);
    Node* nxt = &head;
    while(true){
        if(count == num){
            tmp->next = nxt->next;
            nxt->next = tmp;
            break;
        }
        count++;
        nxt = nxt->next;
    }
}

void removeNode(int data) 
{
    Node* nxt = &head;
    while(nxt->next->next != nullptr){
        if(nxt->next->data == data){
            nxt->next = nxt->next->next;
            break;
        }
        nxt = nxt->next;
    }
}

int getList(int output[MAX_NODE]) 
{
    int idx = 0;
    Node* nxt = &head;
    while(nxt->next->next != nullptr){
        output[idx] = nxt->next->data;
        idx++;
        nxt = nxt->next;
    }
    //printf("%d\n", idx);
    return idx;
}