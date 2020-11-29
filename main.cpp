/* Test dynamic allocation of array  (TestDynamicArray.cpp) */
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	const int SIZE = 5;
	int * pArray;

	pArray = new int[SIZE];  // Allocate array via new[] operator

	// Assign random numbers between 0 and 99
	for (int i = 0; i < SIZE; ++i) {
		*(pArray + i) = rand() % 100;
	}
	// Print array
	for (int i = 0; i < SIZE; ++i) {
		cout << *(pArray + i) << " ";
	}
	cout << endl;

	delete[] pArray;  // Deallocate array via delete[] operator
	return 0;
}