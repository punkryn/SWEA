#include <iostream>
using namespace std;

int arr[] = {3, 2, 2, 1, 8, 1, 4, 5, 9, 1, 1, 1, 1, 1};
int sorted[10];

void merge(int left, int mid, int right){
	int l = left;
	int r = mid + 1;
	int k = left;

	while(l <= mid && r <= right){
		if(arr[l] <= arr[r]){
			sorted[k++] = arr[l++];
		}
		else{
			sorted[k++] = arr[r++];
		}
	}

	if(l > mid){
		while(r <= right)
			sorted[k++] = arr[r++];
	}
	else
		while(l <= mid)
			sorted[k++] = arr[l++];

	for(int i = left; i <= right; i++){
		arr[i] = sorted[i];
	}
}

void mergesort(int left, int right){
	if(left < right){
		int mid = (left + right) / 2;
		mergesort(left, mid);
		mergesort(mid + 1, right);
		merge(left, mid, right);
	}
}

void qsort(int left, int right){
	int s = left;
	int e = right;

	int pivot = arr[(left + right) / 2];

	if(left >= right) return;

	while(s <= e){
		while(arr[s] > pivot) s++;
		while(arr[e] < pivot) e--;

		if(s <= e){
			// arr[s] ^= arr[e];
			// arr[e] ^= arr[s];
			// arr[s] ^= arr[e];
			int tmp;
			tmp = arr[s];
			arr[s] = arr[e];
			arr[e] = tmp;

			s++; e--;
		}
	}
	qsort(left, e);
	qsort(s, right);
}

int binarysearch(int s, int e, int target){
	int mid;
	while(s <= e){
		mid = (s + e) / 2;
		// printf("%d %d %d\n", s, e, mid);
		if(arr[mid] < target){
			s = mid + 1;
		}
		else if(arr[mid] > target){
			e = mid - 1;
		}
		else{
			return mid;
		}
	}
	return -1;
}

int binaryupper(int s, int e, int target){
	int mid;
	int ans = e;

	while(s <= e){
		mid = (s + e) / 2;
		printf("%d %d %d\n", s, e, mid);
		if(arr[mid] > target){
			e = mid - 1;
			ans = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int binarylower(int s, int e, int target){
	int mid;
	int ans = s;

	while(s <= e){
		mid = (s + e) / 2;
		if(arr[mid] >= target){
			e = mid - 1;
			ans = mid;
		}
		else{
			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	mergesort(0, 12);
	//qsort(0, 12);
	
	for(int i = 0; i <= 12; i++) printf("%d ", arr[i]);
	printf("\n");

	printf("%d %d %d", binarysearch(0, 12, 5), binarylower(0, 12, 1), binaryupper(0, 12, 1));

	return 0;
}