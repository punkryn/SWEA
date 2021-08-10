#include <iostream>
#include <cstring>

using namespace std;

#define HASH_SIZE 1 << 18
#define MAXN 100000
#define DIV (HASH_SIZE - 1)

typedef unsigned long long ll;

bool strCmp(char a[], char b[]) {
	int i = 0;

	for (; a[i]; i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return a[i] == b[i];
}

void strCpy(char dst[], char src[]) {
	while (*src) {
		*dst++ = *src++;
	}

	*dst = 0;
}


struct Node {
	char key[11];
	int data;
	Node *next;

	Node *alloc(char _key[], int _data, Node *_next) {
		strCpy(key, _key);
		data = _data;
		next = _next;
		return this;
	}

	/* 찾는 node의 바로 이전 node를 반환한다. */
	Node *getPrevNode(char _key[]) {
		Node *ptr = this;

		while (ptr->next) {
			if (strCmp(_key, ptr->next->key)) {
				break;
			}
			ptr = ptr->next;
		}

		return ptr;
	}
};


int bCnt;
Node buf[MAXN];
Node hashTable[HASH_SIZE];


void init()
{
	bCnt = 0;
	for (int i = 0; i < HASH_SIZE; ++i) {
		hashTable[i].next = 0;
	}
}


ll getKey(char str[]) {
	ll key = 5381;

	for (int i = 0; str[i]; ++i) {
		key += ((key << 5) + key) + (str[i] - 'a' + 1);
	}

	return key & DIV;
}


int find(char key[])
{
	Node *prevNode;
	int target = getKey(key);
	prevNode = hashTable[target].getPrevNode(key);

    if(prevNode->next != 0)
	    return prevNode->next->data;
    else
        return -1;
}


void add(char key[], int data)
{
	int target = getKey(key);
	hashTable[target].next = buf[bCnt++].alloc(key, data, hashTable[target].next);
}


int remove(char key[])
{
	Node *prevNode, *targetNode;
	int target = getKey(key);
	prevNode = hashTable[target].getPrevNode(key);
    if(prevNode->next == 0){
        cout << "NO" << '\n';
        return -1;
    }
	targetNode = prevNode->next;

	prevNode->next = targetNode->next;
    return targetNode->data;
}

int main(){
    init();
    char str[10] = "abc";
    add(str, 3);
    cout << find(str) << '\n';
    cout << remove(str) << '\n';

    cout << find(str) << '\n';
    cout << remove(str) << '\n';

    char str2[10] = "axcvaf";
    add(str2, 5);
    add(str2, 4);

    cout << find(str2) << '\n';

    return 0;
}