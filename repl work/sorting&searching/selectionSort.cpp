#include <iostream>
using namespace std;

void selectionSort(int * arr, int n) {
	int pos_min,temp;
	for (int i=0; i < n-1; i++) {
		pos_min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[pos_min])
				pos_min=j;
		}
		cout << "Swap " << arr[i] << " and " << arr[pos_min] << endl;
		temp = arr[i];
		arr[i] = arr[pos_min];
		arr[pos_min] = temp;

		for(int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}

void selectSortTopK (int* arr, int n, int k){
	int pos_max,temp;
	for (int i=n-1; i > (n-k-1); i--) {
		pos_max = 0;
		for (int j=1; j <= i; j++) {
			if (arr[j] > arr[pos_max])
				pos_max=j;
		}
		temp = arr[i];
		arr[i] = arr[pos_max];
		arr[pos_max] = temp;
	}
}

int main(){
	/*
	 * 1)
	 * Robert Brian Victor David Scott
	 * Robert Brian Scott David Victor
	 * Robert Brian David Scott Victor
	 * David Brian Robert Scott Victor
	 * Brian David Robert Scott Victor ✅
	 *
	 * 2)
	 * It would find the smallest value and put it at the end, consequently sorting the array backwards.
	 *
	 * 3)
	 * a) Check if the value is in it's right position before swapping
	 * b) more code, longer runtimes (more checks), logically harder to maintain code
	 *
	 * 4)
	 * 8 9 6 1 2 4
	 * 1 9 6 8 2 4
	 * 1 2 6 8 9 4
	 * 1 2 4 8 9 6
	 * 1 2 4 6 9 8
	 * 1 2 4 6 8 9 ✅
	 */
	int * arr = new int[6]{8, 9, 6, 1, 2, 4};
	selectionSort(arr, 6);
	delete[] arr;

	arr = new int[6]{8, 9, 6, 1, 2, 4};
	selectSortTopK(arr, 6, 3);
	for(int i = (6-3); i < 6; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}