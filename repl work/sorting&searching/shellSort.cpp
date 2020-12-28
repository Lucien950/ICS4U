#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <random>
#include <sys/timeb.h>

int getMilliCount(){
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}
int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

using namespace std;

void insertionSort(int * arr, int size){
	for (int i = 1; i < size; i++){
		int pointValue = arr[i];
		if(pointValue == -1){
			continue;
		}
		int toSlide = i - 1;

		//Slide previous values if necessary
		while (toSlide >= 0 && arr[toSlide] > pointValue){
			arr[toSlide + 1] = arr[toSlide];
			toSlide--;
		}
		//Place the final value in the correct position
		arr[toSlide + 1] = pointValue;
	}
}

void shellSort(int * arr, int size, int k, int(*nextFunc)(int)){
	if(k < 1 || k >= size){
		return;
	}
	//Split into k
	int subLength = ceil((size + 0.0)/k);

	int ** sub = new int*[k];
	for(int i = 0; i < k; i++){
		sub[i] = new int[subLength];
	}
	for(int i = 0; i < k; i++){
		for(int j = i; j < k*subLength; j += k){
			if(j >= size){
				sub[i][(j-i)/k] = -1;
			}else{
				sub[i][(j-i)/k] = arr[j];
			}
		}
	}

	//SORT
	for(int i = 0; i < k; i++){
		insertionSort(sub[i], subLength);
	}

	//MERGE IT BACK IN
	int index = 0;
	for(int j = 0; j < subLength; j++){
		for(int i = 0; i < k; i++){
			if(sub[i][j] != -1){
				arr[index] = sub[i][j];
				index++;
			}
		}
	}

	//PRINTING. REMOVE FOR BEST TIMES
//	for(int i = 0; i < k; i++){
//		for(int k = 0; k < i; k++){
//			cout << "  ";
//		}
//		for(int j = 0; j < subLength; j++){
//			cout << setw(4) << sub[i][j];
//			for(int o = 0; o < k-1; o++){
//				cout << " ";
//			}
//		}
//		cout << endl;
//	}
	shellSort(arr, size, nextFunc(k), nextFunc);
}

int genK(int size){
	int k = 1;
	while((pow(3, k)-1)/2 <= (size/3.0)){
		k++;
	}
	return (pow(3, k-1)-1)/2;
}
int nextK(int k){
	return ((2*k+1)/3-1)/2;
}

int gen2K(int size){
	return round(size/2);
}
int next2K(int k){
	return round(k/2);
}

void printARR(int * arr, int size){
	for(int i = 0; i < size; i++){
		cout << setw(3) << arr[i] << " ";
		if((i+1) % 15 == 0){
			cout << endl;
		}
	}
	cout << endl;
}

int main(){
	/*
	 *  26 37 21 41 63 19 61 72 55 29 47 18 26 22
	 *  19             26             47
	 *     18             37             61
	 *        21             26             72
	 *            22            41             55
	 *               29            63
	 *  19 18 21 22 29 26 37 26 41 63 47 61 72 55
	 *
	 *  26 37 21 41 63 19 61 72 55 29 47 18 26 22
	 *  26			26			55			63
	 *     19		   22		   29		   37
	 *     	  21		  47		  61
	 *     	  	 18			 41			 72
	 *  26 19 21 18 26 22 47 41 55 29 61 72 63 37
	 *
	 *  RESPONSE
	 *  Shell sort is an effective preliminary sorting algorithm to help prime the data for insertion sort, especially with large numbers
	 *  	Due to the incremental nature of shellsort, especially with larger k values, by taking a sample of all the numbers and sorting them, we move values to their general correct positions
	 *  	By moving values closer to their final positions, it requires less comparisons to complete insertion sort.
	 *
	 *  	Thus, by using k = 1, you do get insertion sort, but by cleverly employing multiple k values, you can approximate the best case scenario for insertion sort
	 */

	int n = 14;
	int * arr = new int[n]{26, 37, 21, 41, 63, 19, 61, 72, 55, 29, 47, 18, 26, 22};
	int k = genK(n);
	for(int i = 1; i < n; i++){
		if(arr[i] > k && arr[i] < n){
			k = arr[i];
		}
	}

	shellSort(arr, n, k, nextK);
	delete[] arr;

	arr = new int[500];
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<> dist(1,999);

	for(int i = 0; i < 500; i++){
		arr[i] = dist(mt);
	}
	cout << "Array here:" << endl;
	printARR(arr, 500);
	cout << endl;
	int start = getMilliCount();
	shellSort(arr, 500, genK(500), nextK);
	cout << "Sorted Array:" << endl;
	printARR(arr, 500);
	cout << "Base time " << getMilliSpan(start) << endl;

	for(int i = 0; i < 500; i++){
		arr[i] = dist(mt);
	}
	cout << "Array here:" << endl;
	printARR(arr, 500);
	cout << endl;
	start = getMilliCount();
	shellSort(arr, 500, gen2K(500), next2K);
	cout << "Sorted Array:" << endl;
	printARR(arr, 500);
	cout << "Second time " << getMilliSpan(start) << endl;
}