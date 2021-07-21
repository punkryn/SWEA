/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node node[4001];

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
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
}

Node* getNode(int data){
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    node[nodeCnt].prev = nullptr;
    return &node[nodeCnt++];
}

void add2tail(int data){
    Node* tmp = getNode(data);
    tmp->next = tail;
    tmp->prev = tail->prev;
    tail->prev->next = tmp;
    tail->prev = tmp;
}

void add2num(int num, Node* start){
    Node* tmp = getNode(num);
    tmp->prev = start;
    tmp->next = start->next;
    start->next->prev = tmp;
    start->next = tmp;
}

Node* getPos(int x){
    Node* nxt = head;
    for(int i = 0; i < x; i++){
        nxt = nxt->next;
    }
    return nxt;
}

void remove(int x, int y){
    Node* nxt = head;
    for(int i = 0; i < x; i++){
        nxt = nxt->next;
    }
    Node* nxt2 = nxt;
    for(int i = 0; i < y; i++){
        nxt2 = nxt2->next;
    }
    nxt->next = nxt2->next;
    nxt2->next->prev = nxt;
    // for(int i = 0; i < y; i++){
    //     nxt->next = nxt->next->next;
    //     nxt->next->prev = nxt;
    // }
}

void Print(){
    Node* nxt = head;
    for(int i = 0; i < 10; i++){
        cout << nxt->next->data << ' ';
        nxt = nxt->next;
    }
    cout << endl;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	//cin>>T;
    T = 10;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
    int length;
    int data;
    int cmdline;
    char cmd;
    int x, y, s;
    Node* start;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        cin >> length;
        //scanf("%d", &length);
        for(int i = 0; i < length; i++){
            cin >> data;
            //scanf("%d ", &data);
            add2tail(data);
        }
        //Print();
        cin >> cmdline;
        //scanf("%d", &cmdline);
        for(int i = 0; i < cmdline; i++){
            cin >> cmd;
            //scanf("%d ", &cmd);
            switch(cmd){
            case 'I':
                cin >> x >> y;
                //scanf("%d %d ", &x, &y);
                start = getPos(x);
                for(int j = 0; j < y; j++){
                    cin >> s;
                    //scanf("%d ", &s);
                    add2num(s, start);
                    start = start->next;
                }
                //Print();
                break;
            case 'D':
                cin >> x >> y;
                //scanf("%d %d ", &x, &y);
                remove(x, y);
                //Print();
                break;
            case 'A':
                cin >> y;
                //scanf("%d ", &y);
                for(int j = 0; j < y; j++){
                    cin >> s;
                    //scanf("%d ", &s);
                    add2tail(s);
                }
                //Print();
                break;
            }
        }
        
        cout << '#' << test_case << ' ';
        Print();
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}