#include <iostream>
#include <math.h>
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

void reverseArray(int arr[])
{
	int start = 0;
	int end = sizeof(arr)/sizeof(arr[0]);

	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

int main(){
	int x = 0;
	int y = 0;

	bool badInput = true;
	while(badInput) {
		cout << "Start Value:" << endl;
		cin >> x;
		cout << "End Value:" << endl;
		cin >> y;

		if(y <= x){
			cout << "Bad Input, try again" << endl;
			continue;
		}
		badInput = false;
	}

	//CREATE AN ARRAY FOR THE RANGE
	int *arr;
	arr = new int[y-x];
	for(int i = 0; i <= y-x; i++){
		arr[i] = x+i;
	}


	//Print the thing
	//GET THE SPIRALS WIDTH AND HEIGHT
	int height = ceil(sqrt(y-x));
	int width = round(sqrt(y-x));

	//CREATE THE SCAFFOLD FOR THE FINAL ARRAY
	int **templateArr;
	templateArr = new int*[height];
	for(int i = 0; i < height; i++){
		templateArr[i] = new int[width];
		for(int j = 0; j < width; j++){
			templateArr[i][j] = j + width *i + 1;
		}
	}



	int *orderArr = spiraler(height, width, templateArr);
	cout << "orderArr activities" << endl;
	for(int i = 0; i < height * width; i++){
		cout << orderArr[i] << endl;
	}


	int ** finalArr = new int*[width];

	cout << "Final Output" << endl;
//	for(int i = 0; i < height; i++){
//		for(int j = 0; j < width; j++){
//			cout << finalArr[i][j] << " ";
//		}
//		cout << endl;
//	}
	return 0;
}