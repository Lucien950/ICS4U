#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;

int* spiraler(int m, int n, int ** a){
	int k = 0, l = 0, it=0;
	int * out;
	out = new int[m*n];

	while (k < m && l < n) {
		//=============Up mode=============
		/* Print the first row from the remaining rows */
		for (int i = l; i < n; ++i) { // i from l to n
			out[it] = a[k][i];
			it++;
		}
		k++;

		/* Print the last column from the remaining columns */
		for (int i = k; i < m; ++i){ // i from k to m
			out[it] = a[i][n - 1];
			it++;
		}
		n--;


		//=============Down mode=============
		/* Print the last row from the remaining rows */
		if (k < m) {
			for (int i = n - 1; i >= l; --i) {// n-1 down to l
				out[it] = a[m - 1][i];
				it++;
			}
			m--;
		}

		/* Print the first column from the remaining columns */
		if (l < n) {
			for (int i = m - 1; i >= k; --i) {//m-1 down to k
				out[it] = a[i][l];
				it++;
			}
			l++;
		}
	}

	return out;
}

void reverseArray(int arr[], int end)
{
	int start = 0;

	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void printIT(int ** arr, int height, int width){
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(arr[i][j] == -1){
				cout << setw(2) << "__ ";
			}else{
				cout << setw(2) << arr[i][j] << " ";
			}
		}
		cout << endl;
	}
}

int main(){
	int start = 0;
	int end = 0;

	bool badInput = true;
	while(badInput) {
		cout << "Start Value:" << endl;
		cin >> start;
		cout << "End Value:" << endl;
		cin >> end;

		if(end <= start){
			cout << "Bad Input, try again" << endl;
			continue;
		}
		badInput = false;
	}

	//CREATE AN ARRAY FOR THE RANGE
	int *arr;
	arr = new int[end - start];
	for(int i = 0; i <= end - start; i++){
		arr[i] = start + i;
	}


	//Print the thing
	//GET THE SPIRALS WIDTH AND HEIGHT
	int height = 1, width = 1;
	while(width * height <= end-start){
		if(height < width){
			height++;
		}else{
			width++;
		}
	}
	cout << "Height " << height << ", Width " << width << endl;

	//CREATE THE SCAFFOLD FOR THE FINAL ARRAY
	int **templateArr;
	templateArr = new int*[height];
	for(int i = 0; i < height; i++){
		templateArr[i] = new int[width];
		for(int j = 0; j < width; j++){
			templateArr[i][j] = j + width *i + 1;
		}
	}


	int * orderArr;
	orderArr = spiraler(height, width, templateArr);
	cout << endl;
	for(int i = 0; i < width * height; i++){
		cout << orderArr[i] << " ";
	}
	cout << endl;
	cout << endl;


	int ** finalArr = new int*[height];
	for(int i = 0; i < height; i++){
		finalArr[i] = new int[width];
		for(int j = 0; j < width; j++){
			finalArr[i][j] = -1;
		}
	}

	for(int i = start; i <= end; i++){
		int position = orderArr[(width*height)-(i-start)-1];
		int xPos = (position - 1) % width;
		int yPos = floor((position-1)/width);

		finalArr[yPos][xPos] = i;
	}

	//PRINT OUT
	cout << endl << "Final Output" << endl;
	printIT(finalArr, height, width);
	return 0;
}