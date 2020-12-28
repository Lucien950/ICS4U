#include <iostream>
using namespace std;

void shakerSort(double * arr, int size){
	int min = 0, max = size;
	int index = 1;

	while(true){
		if(min >= max){
			return;
		}

		while(index < size-1){
			if(arr[index] < arr[index - 1]){
				int temp = arr[index];
				arr[index] = arr[index-1];
				arr[index-1] = temp;
			}
			for(int i = 0; i < size; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
			index++;
		}
		max--;

		while(index > 1){
			if(arr[index] < arr[index-1]){
				int temp = arr[index];
				arr[index] = arr[index- 1] ;
				arr[index - 1] = temp;
			}
			for(int i = 0; i < size; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
			index--;
		}
		min++;
	}
}


int main(){
	/*
	 * 3 8 3 2 7 5
	 * 3 8 3 2 7 5
	 * 3 3 8 2 7 5
	 * 3 3 2 8 7 5
	 * 3 3 2 7 8 5
	 * 3 2 3 7 8 5
	 * 2 3 3 7 8 5
	 * 2 3 3 7 5 8
	 * 2 3 3 5 7 8 (SORTED!)
	 *
	 * 2)
	 * Make the comparasions the other way round (swap when left is smaller than right)
	 *
	 * 3)
	 * 2 9 4 6 1 7 4
	 * 2 4 6 1 7 4 9
	 * 2 4 4 6 1 7 9
	 * 2 4 4 1 6 7 9
	 * 1 2 4 4 6 7 9
	 */

	auto * arr = new double[7]{2, 9, 4, 6, 1, 7, 4};
	shakerSort(arr, 7);
}