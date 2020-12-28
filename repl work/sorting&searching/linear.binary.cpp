#include <iostream>
#include <random>
#include <bits/stdc++.h>
using namespace std;

int* CreateRndArray(int low, int high, int size){
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<> dist(low,high);
	int* out;
	out = new int[size];
	for(int i = 0; i < size; i++){
		out[i] = dist(mt);
	}
	sort(out, out + size);
	return out;
}

int* cut(const int * arr, int front, int back){
	int* out = new int[back - front];
	for(int i = 0; i <= back-front; i++){
		out[i] = arr[i + front];
	}

	return out;
}

int linearSearch(const int* arr, int search, int size){
	for(int i = 0; i < size; i++){
		if(arr[i] == search){
			return i;
		}
	}
	return -1;
}

int binarySearch(const int* arr, int search, int size){
	int min = 0, max = size - 1;
	int head = round((max + min)/2)-1;

	while(search){
		if(arr[head] < search){
			min = head;
		}else if(arr[head] > search){
			max = head;
		}else{
			return head;
		}

		if(max - min <= 1){
			return -1;
		}
		head = (min + max)/2;

		int* temp = cut(arr, min, max);
		for(int i = 0; i < max-min; i++){
			cout << temp[i] << " ";
		}
		cout << endl;
	}

	return -2;
}

int main(){
	cout << "PROOF FUNCTIONS WORK" << endl;
	int * arr = new int[10];
	for(int i = 0; i < 10; i++){
		arr[i] = i;
	}

	cout << linearSearch(arr, 12, 10) << endl;
	cout << binarySearch(arr, 12, 10) << endl;

	int * second = cut(arr, 0, 5);
	for(int i = 0; i < 6; i++){
		cout << second[i] << endl;
	}
	delete[] arr;
	cout << endl << endl;

	int elementNum, lower, upper;

	cout << "Enter number of elements: ";
	cin >> elementNum;
	cout << "Enter lower limit: ";
	cin >> lower;
	cout << "Enter upper limit: ";
	cin >> upper;

	cout << endl;


	cout << "Your values are:" << endl;
	arr = CreateRndArray(lower, upper, elementNum);
	for(int i = 0; i < elementNum; i++){
		cout << arr[i] << " ";
	}

	cout << endl << endl;

	while(true){
		cout << "Please enter an integer value (-1 to quit): ";
		int findValue;
		cin >> findValue;
		if(findValue == -1){
			return 0;
		}

		int result = binarySearch(arr, findValue, elementNum);
		if(result == -1){
			cout << "The integer " << findValue << " was not found." << endl;
		}else{
			cout << "The integer " << findValue << " was found at position " << result << "." << endl;
		}
	}
}