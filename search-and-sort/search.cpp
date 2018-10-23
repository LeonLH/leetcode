#include<iostream>
using namespace std;
int binarySearch(int arr[], int n, int key){
	int low = 0;
	int high = n-1;
	int mid; 
	while(low <= high){
		mid = (low + high)/2;
		if(key == arr[mid])
			return mid;
		else if(key < arr[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

void insertSort(int arr[], int n){
	int i, j, key;
	for(i=1; i < n; ++i){
		key = arr[i];
		for(j = i-1; j >= 0 && key < arr[j]; --j)
			arr[j+1] = arr[j];
		arr[j+1] = key;
	}
}

void printArray(int arr[], int n){
	cout << "\n\t\tThe array is:\t";
	for(int i = 0; i < n; ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int A[] = {34, 56, 76, 23, 26, 74, 27, 32};
	insertSort(A, sizeof(A)/sizeof(int));
	printArray(A, sizeof(A)/sizeof(int));
	
	int pos = binarySearch(A, sizeof(A)/sizeof(int), 32);
	cout << "\t\tThe position is: \t" << pos+1 << endl;
	return 0;
}
