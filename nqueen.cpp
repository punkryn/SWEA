#include <iostream>
#include <cmath>

#define MAX_SIZE 14
// �ִ� MAX_SIZE queen �������� �ذ��� �� �ִ�.

using namespace std;

int board[MAX_SIZE];
// board[i]�� i��° �࿡ ���� ���° ���� �ִ��� �ǹ��ϴ� �����̴�. (�࿭�� ���� �ٲ� �ȴ�.)
// �� board[0] = 3�϶�, (1,4) Ȥ�� (4,1) ��ġ�� ���� �ִٴ� ���̴�.
int n;
int cnt;

void path(int y) {
	// y�� ���� ��� ���� ��ġ�Ǿ������� �ǹ��ϴ� ������.
	int ko;
	if( y == n ) {
		// n���� ���� ��ġ�� �Ǿ��ٸ� �� ���� ���̴�.
		cnt++;
		return;
	}
	for( int i=0; i<n; i++ ) {
		// ko�� ���� ��ġ�� �� �ִ����� �����ϴ� �÷��״�.
		ko = 1;
		for( int j=0; j<y; j++ ) {
			// �̹� ��ġ�� ���� ���� �����ؼ� i��° ĭ�� ���� ��ġ�� �� �ִ����� Ȯ���Ѵ�.
			if( board[j] == i || abs(y-j) == abs(i-board[j]) ) {
				// j��° �ٿ� �ִ� ���� ���� ĭ�� �ְų�, �밢���� ���� ���� �ִٸ�, i��° ĭ�� ���� Ž���� �ߴ��Ѵ�.
				ko = 0;
				break;
			}
		}
		if( ko ) {
			// ������� �Դٸ� y��° �ٿ� i��° ĭ�� ���� ���δ� ���� �����ϴ�.
			board[y] = i;
			path(y+1);
		}
	}
}

int main() {


	
    cin >> n;
    cnt = 0;
    path(0);

    cout << cnt << '\n';
	

	return 0;
}