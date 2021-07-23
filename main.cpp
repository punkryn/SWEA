#include <iostream>
using namespace std;

int memPoolCnt;

struct Node {
	int value;
	Node* prev;
} node[50000];

struct User {
	Node* data;
} user[100000];

int getSize(Node* data){
    int count = 0;
    while(data != nullptr){
        data = data->prev;
        count += 1;
    }
    return count;
}

int main() {
	memPoolCnt = 0; //초기화
	
    if(user[0].data == nullptr){
        cout << "yes" << endl;
    }

	// 첫 번째 데이터 추가
	Node* tmp1 = &node[memPoolCnt++]; // 메모리 풀에서 가져옴
	tmp1->value = 1;
	tmp1->prev = user[0].data;
	user[0].data = tmp1;

    

	// 두 번째 데이터 추가
	Node* tmp2 = &node[memPoolCnt++]; // 메모리 풀에서 가져옴
	tmp2->value = 2;
	tmp2->prev = user[0].data;
	user[0].data = tmp2;

    int cnt = getSize(user[0].data);
    cout << cnt << endl;

	return 0;
}