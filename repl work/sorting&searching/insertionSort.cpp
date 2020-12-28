#include <iostream>
#include <math.h>
using namespace std;

void insertionSort(int * arr, int size){
	for (int i = 1; i < size; i++){
		int pointValue = arr[i];
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

void descInsertionSort(int * arr, int size){
	for (int i = 1; i < size; i++){
		int pointValue = arr[i];
		int toSlide = i - 1;

		//Slide previous values if necessary
		while (toSlide >= 0 && arr[toSlide] < pointValue){
			arr[toSlide + 1] = arr[toSlide];
			toSlide--;
		}
		//Place the final value in the correct position
		arr[toSlide + 1] = pointValue;
	}
}

void stringInsertionSort(string * arr, int size){
	for (int i = 1; i < size; i++){
		string pointValue = arr[i];
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


int main(){
	int* arr = new int[7] {6, 2, 8, 3, 1, 7, 4};
	insertionSort(arr, 7);
	for(int i = 0; i < 7; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;


	//2 -> Flip the comparasion
	arr = new int[7] {6, 2, 8, 3, 1, 7, 4};
	descInsertionSort(arr, 7);
	for(int i = 0; i < 7; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr;

	//3
	string * planetArr = new string[8]{"Mecury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Neptune", "Uranus"};
	stringInsertionSort(planetArr, 8);

	for(int i = 0; i < 8; i++){
		cout << planetArr[i] << " ";
	}
	cout << endl;

	cout << "How many values?";
	int valueNum;
	cin >> valueNum;
	int * numArray = new int[valueNum];
	for(int i = 0; i < valueNum; i++){
		cin >> numArray[i];
	}
	insertionSort(numArray, valueNum);
	if(valueNum % 2 != 0){
		cout << "The median is " << numArray[int(floor(valueNum/2.0))] << endl;
	}else{
		cout << "The media is " << (numArray[valueNum/2]+numArray[valueNum/2-1])/2.0 << endl;
	}

	/*
	 5
	 Yes
	 The shift value can only be changed if the value comparison is STRICTLY greater. If they are equal, the
	 value comparison fails, and the values are not swapped
	 */
}

