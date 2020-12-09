#include <iostream>
#include <bits/stdc++.h>
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
    cout << "Enter array to be printed backwards (6 elements)" << endl;
    int *arr;
    arr = new int[6];
    for(int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    for(int i = 5; i >= 0; i--){
    	cout << arr[i] << " ";
    }
    cout << endl << endl;
    delete[] arr;

    //Q1 c)
    arr = new int[50];
    int sum = 0;
    for(int i = 0; i < 50; i++){
        int toAdd = rand() % 50 + 1;
        sum += toAdd;
        arr[i] = toAdd;
    }
    for(int i = 0; i < 50; i++){
    	cout << arr[i] << " ";
    }
    cout <<  endl << "Sum of random array is " << sum << endl;
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
    for(int i = 0; i < 10; i++){
    	for(int j = 0; j < 10; j++){
    		cout << setw(4) << arr2[i][j] << " ";
    	}
    	cout << endl;
    }
    cout << endl<< "Average of random array is " << (sum/100.0) << endl << endl;

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

	int h1;
	int h2;

    cout << "Height of the first array" << endl;
    cin >> h1;
	arr21 = new int *[h1];
	for(int i = 0; i < h1; i++){
		arr21[i] = new int[width];
	}

    cout  << "Height of the second array" << endl;
    cin >> h2;
	arr22 = new int *[h2];
	for(int i = 0; i < h2; i++){
		arr22[i] = new int[width];
	}

	arr23 = new int *[h1 + h2];
	for(int i = 0; i < h1 + h2; i++){
		arr23[i] = new int[width];
	}

	mt19937 mt (random_device{}());
	uniform_int_distribution<int> dist(1, 100);

	for(int j = 0; j < h1; j++){
		cout << "Value of horizontal row " << (j + 1)  << " in the first subarray"<< endl;
		for(int i = 0; i < width; i++){
			arr21[j][i] = dist(mt);
		}
	}
	for(int j = 0; j < h2; j++){
		cout << "Value of horizontal row " << (j + 1)  << " in the second subarray"<< endl;
		for(int i = 0; i < width; i++){
			arr22[j][i] = dist(mt);
		}
	}

	//Allocate values to the array
    for(int i = 0; i < h1; i++){
        arr23[i] = arr21[i];
    }
    for(int i = 0; i < h2; i++){
        arr23[i+h1] = arr22[i];
    }

    //PRINT THE ARRAY!!!
	for(int i = 0; i < h1 + h2; i++){
		for(int j = 0; j < width; j++) {
			cout << setw(2) << arr23[i][j] << " ";
		}
		cout << endl;
    }
	cout << endl;

    delete[] arr21;
    delete[] arr22;
    delete[] arr23;




    //Passing Arrays to Functions Example 1
    int array[5] = {1, 2, 3, 4, 5};
    modifyArray(array);
    for(int i : array){
    	cout << i << " ";
    }
    cout << endl;

	cout << endl << array[0] << endl;
	modifyElement(&array[0]);
	cout << endl;

    for(int i : array) {
		cout << i << " ";
	}
	cout << endl;

    return 0;
}