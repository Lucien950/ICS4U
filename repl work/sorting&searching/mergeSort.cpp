#include <iostream>
#include <random>
using namespace std;

void merge(int * items, int start, int mid, int end, int length) {
	int * temp = new int[length];
	int pos1 = start;
	int pos2 = mid + 1;
	int spot = start;
	while (!(pos1 > mid && pos2 > end)) {
		if ((pos1 > mid) || ((pos2 <= end) && (items[pos2] < items[pos1]))) {
			temp[spot] = items[pos2];
			pos2 += 1;
		} else {
			temp[spot] = items[pos1];
			pos1 += 1;
		}
		spot += 1;
	}
/* copy values from temp back to items */
	for (int i = start; i <= end; i++) {
		items[i] = temp[i];
	}
}

void mergesort(int * items, int start, int end, int length) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(items, start, mid, length);
		mergesort(items, mid + 1, end, length);
		merge(items, start, mid, end, length);
	}
}

int main(){
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<> dist(1,10);

	int * arr = new int[10];
	for(int i = 0; i < 10; i++){
		arr[i] = dist(mt);
	}

	for(int i = 0; i < 10; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	mergesort(arr, 0, 10-1, 10);
	for(int i = 0; i < 10; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}