#include<iostream>

using namespace std;

int A[100000];
int C[100000];
long total;

void merge(int left, int mid, int right){
    int p = left;
    int q = mid + 1;
    int idx = left;

    while (p <= mid && q <= right){
        if(A[p] > A[q]){
            C[idx] = A[q];
            total += mid - p + 1;
            //cout << total << '\n';
            idx++;
            q++;
        }
        else {
            C[idx++] = A[p++];
        }
    }

    while(p <= mid){
        C[idx++] = A[p++];
    }
    while(q <= right){
        C[idx++] = A[q++];
    }

    for(int i = left; i <= right; i++){
        A[i] = C[i];
    }
}

void mergesort(int left, int right){
    int mid;
    if (left < right){
        mid = (left + right) / 2;
        mergesort(left, mid);
        mergesort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	int test_case;
	int T;
	
	freopen("C:\\Users\\gns81\\Dropbox\\SWEA\\SWEA\\divide_conquer\\inversion.txt", "r", stdin);
	cin>>T;
	int n;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        total = 0;
        for(int i = 0; i < n; ++i) cin >> A[i];
        mergesort(0, n-1);
        for(int i = 0; i < n; ++i) cout << A[i] << ' ';
        cout << '#' << test_case << ' ' << total << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}