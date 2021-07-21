#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

int main() {
	Node* head;
    Node a;
    head = &a;
    head->data = 1;
    cout << head->data << endl;
	return 0;
}