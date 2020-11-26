#include <iostream>
#include <random>

using namespace std;

void modifyArray(int arr[]){
	for(int i = 0; i < 5; i++){
		arr[i]= arr[i] * 2;
	}
}
void modifyElement(int *i){
	*i *= 2;
	cout << *i << endl;
}

int main(){

    //1D b)
    cout << "Enter array to be printed backwards" << endl;
    int *arr;
    arr = new int[6];
    for(int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    for(int i = 5; i >= 0; i--){
    	cout << arr[i] << endl;
    }
    delete[] arr;

    //Q1 c)
    arr = new int[50];
    int sum = 0;
    for(int i = 0; i < 50; i++){
        int toAdd = rand() % 50 + 1;
        sum += toAdd;
        arr[i] = toAdd;
    }
    cout << endl << "Sum of random array is " << sum << endl;
    delete[] arr;

    //2D b)
    sum = 0;
    int **arr2;
    arr2 = new int*[10];
    for(int i=0; i<10; ++i){
        arr2[i]=new int[10]; //creates new 'column' number of locations
        for(int j = 0; j < 10; j++){
            int toAdd = rand() % 1000 + 1;
            arr2[i][j] = toAdd;
            sum += toAdd;
        }
    }
    cout << "Average of random array is " << (sum/100.0) << endl;

    delete[] arr2;

    //c)
    int n = 5;
    arr2 = new int*[n];
    for(int i = 0; i < n; i++){
        arr2[i] = new int[n];
        arr2[i][i] = 1;
    }
    delete[] arr2;

    //Example 2
    int **arr21, **arr22, **arr23;

    cout << "What is the width of the arrays" << endl;
    int width;
    cin >> width;


    arr23 = new int *[width];
	int h1;
	int h2;

    cout << "Height of the first array" << endl;
    cin >> h1;
	arr21 = new int *[width];
    cout  << "Height of the second array" << endl;
    cin >> h2;
	arr22 = new int *[width];

	for(int j = 0; j < width; j++){
		cout << "Value of column " << (j + 1)  << " in the first subarray"<< endl;
		int *toAdd = new int[h1 + h2];
		for(int i = 0; i < h1; i++){
			cin >> toAdd[i];
		}
		cout << "Value of column " << (j + 1)  << " in the second subarray"<< endl;
		for(int i = 0; i < h2; i++){
			cin >> toAdd[i + h1];
		}
		arr23[j];
	}

	//Allocate values to the array
    for(int i = 0; i < (sizeof(arr21)/sizeof(*arr21)); i++){
        arr23[i] = arr21[i];
    }
    for(int i = 0; i < (sizeof(arr22)/sizeof(*arr22)); i++){
        arr23[i+(sizeof(arr21)/sizeof(*arr21))] = arr22[i];
    }
    delete[] arr21;
    delete[] arr22;
    delete[] arr23;

    //Passing Arrays to Functions Example 1
    int array[5] = {1, 2, 3, 4, 5};
    modifyArray(array);
    for(int i : array){
    	cout << i << endl;
    }

	cout << endl << array[0] << endl;
	modifyElement(&array[0]);
    cout << array[0] << endl << endl;

    for(int i : array) {
		cout << i << endl;
	}

    return 0;
}