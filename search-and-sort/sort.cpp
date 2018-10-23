#include<iostream>
using namespace std;
// Insert sort
void insertSort(int arr[], int n){
	int i, j, key;
	for(i = 1; i < n; i++){
		key = arr[i];
		for(j=i-1; j >= 0 && key < arr[j] ; --j)
			arr[j+1] = arr[j];
		arr[j+1] = key;
	}
}
void binInsertSort(int arr[], int n){
	int i, j, key;
	for(i = 1; i < n; ++i){
		key = arr[i];

		int low = 0, high = i-1, mid;
		while(low <= high){
			mid = (low + high)/2;
			if(key < arr[mid]) 
				high = mid - 1;
			else
				low = mid + 1;
		}
		for(j = i-1; j >= low; --j)
			arr[j+1] = arr[j];

		arr[low] = key;
	}
}

void shellSort(int arr[], int n){
	int i, j, dk, key;
	for(dk = n/2; dk >= 1; dk = dk/2)
		for(i = dk; i < n; ++i)
			if(arr[i] < arr[i-dk]){
				key = arr[i];
				for(j = i - dk; j >= 0 && key < arr[j]; j -= dk)
					arr[j+dk] = arr[j];
				arr[j+dk] = key;
			}
}
/* Sentinel: forloop i from 2 to n, assign arr[0] to arr[i], and don't need judge if it is out of bounds; 
	for(i=2; i<=n; ++i)
		if(arr[i] < arr[i-1]){
			arr[0] = arr[i];
			for(j=i-1; arr[0] < arr[j]; --j)
				arr[j+1] = arr[j];
			arr[j+1] = arr[0];
		}
*/

// Swap sort
// Smallest move from backward to forward OR Biggest move from forward to backward. 
void bubbleSort(int arr[], int n){
	for(int i = 0; i < n; ++i)
		for(int j = n-1; j > i; --j)
			if(arr[j] < arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;
			}
}

int partition(int arr[], int low, int high){
	int pivot = arr[low];
	while(low < high){
		while(low < high && arr[high] >= pivot)
			--high;
		arr[low] = arr[high];
		while(low < high && arr[low] <= pivot)
			++low;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}

void quickSort(int arr[], int low, int high){
	if(low < high){
		int pivotpos = partition(arr, low, high);
		quickSort(arr, low, pivotpos-1);
		quickSort(arr, pivotpos+1, high);
	}
}

/*
void bubbleSort0(int A[], int nlen){
	int i = 0;
	int k = nlen;
	while(k > 0){
		i = 0;
		while(i<k-1){
			int j = i+1;
			if(A[j] < A[i]){
				int tmp = A[j];		//swap
				A[j] = A[i];
				A[i] = tmp;
			}
			++i;
		}
		--k;
	}
}
*/
// Select sort
void selectSort(int arr[], int n){
	int i, j, min, tmp;
	for(i = 0; i < n-1; ++i){
		min = i;
		for(j = i+1; j < n; ++j)
			if(arr[j] < arr[min])
				min = j;
		if(min != i){
			tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

void adjustDown(int arr[], int k, int n){	// k = 0 ? 
	int i;
	int tmp = arr[k];
	for(i = 2*k; i < n; i *= 2){
		if(i < n-1 && arr[i] < arr[i+1])
			++i;
		if(tmp >= arr[i])
			break;
		else{
			arr[k] = arr[i];
			k = i;
		}
	}
	arr[k] = tmp;
}
/*
void adjustUp(int arr[], int k){
	int tmp = arr[k];
	int i;
	for(i = k/2; i >= 0 && arr[i] < tmp; i /= 2){
		arr[k] = arr[i];
		k = i;
	}
	arr[k] = tmp;
}
*/
void buildMaxHeap(int arr[], int n){
	for(int i = n/2; i >= 0; --i)
		adjustDown(arr, i, n);
}

void heapSort(int arr[], int n){
	buildMaxHeap(arr, n);
	int tmp, i;
	for(i = n-1; i > 0; --i){
		tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		adjustDown(arr, 0, i);
	}

}

void printArray(int A[], int n){
	for(int i=0; i<n; ++i)
		cout << A[i] << " ";
	cout << endl;

}

int main(){
	int i, j;
	int A[] = {34, 56, 76, 27, 26, 74, 23, 32};
	//buildMaxHeap(A, sizeof(A)/sizeof(int));
	heapSort(A, sizeof(A)/sizeof(int));
	printArray(A, sizeof(A)/sizeof(int));
	return 0;
}
