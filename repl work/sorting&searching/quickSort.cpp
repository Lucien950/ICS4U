#include <iostream>
#include <random>
using namespace std;

void quickSort (int* list, int low, int high){
	int MOVING_LEFT = 0;
	int MOVING_RIGHT = 1;

	if (low < high){
		int left = low;
		int right = high;
		int currentDirection = MOVING_LEFT;
		int pivot = list[low];

		while (left < right){
			if (currentDirection == MOVING_LEFT){ //ah yes, best practices
				while ((list[right] >= pivot) && (left < right)) right--;

				list[left] = list[right];
				currentDirection = MOVING_RIGHT;
			}
			if (currentDirection == MOVING_RIGHT){
				while ((list[left] <= pivot) && (left < right)) left++;

				list[right] = list[left];
				currentDirection = MOVING_LEFT;
			}
		}

		list[left] = pivot;
		quickSort(list, low, left-1);
		quickSort(list, right+1, high);
	}
}

void quickSort (int* list, int length){
	quickSort(list, 0, (length - 1));
}

int main(){
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<> dist(1,10);

	int size = 20;
	int * arr = new int[size];
	for(int i = 0; i < size; i++){
		arr[i] = dist(mt);
		cout << arr[i] << " ";
	}
	cout << endl;
	quickSort(arr, size);
	for(int i = 0; i < size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}