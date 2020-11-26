#include <iostream>
using namespace std;


int main(){
	int x = 0;
	int y = 0;

	cout << "Start Value:" << endl;
	cin >> x;
	cout << "End Value:" << endl;
	cin >> y;

	int *arr;
	arr = new int[y-x];

	for(int i = 0; i <= y-x; i++){
		arr[i] = x+i;
	}

	spiralPrint()

	return 0;
}