#include<iostream>
using namespace std;
void bubbleSort(int A[], int nlen){
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

int main(){
	int A[] = {34, 56, 76, 23, 26, 74, 27, 32};
	bubbleSort(A, sizeof(A)/sizeof(int));
	for(int i=0; (unsigned)i<sizeof(A)/sizeof(int); ++i)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}
