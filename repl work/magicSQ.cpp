#include <iostream>
#include <bits/stdc++.h>
#include <numeric>

using namespace std;

bool checkSquare(int **arr, int n, int sum = 0){
	if(sum == 0){
		for(int row = 0; row < n; row++){
			sum += arr[0][row];
		}
	}
	//check rows
	for(int row = 0; row < n; row++){
		int runSum = 0, oRunSum = 0;
		for(int col = 0; col < n; col++){
			runSum += arr[row][col];
			oRunSum += arr[col][row];
		}
		if(runSum != sum || oRunSum != sum){
			return false;
		}
	}
	//Check diagonals
	int runSum = 0, oRunSum = 0;
	for(int i = 0; i < n; i++){
		runSum += arr[i][i];
		oRunSum += arr[n-i-1][i];
	}
	if(runSum != sum || oRunSum != sum){
		return false;
	}

	//If all checks pass, return true
	return true;
}

/*
General Idea behind this algorithm
Take empty array, place first value at vertically center, rightmost position

(if at any point the number goes over, it wraps to the other side)

Then, repeat this until all numbers are expended:
 	up one, right one
	IF YOU HIT A FILLED POSITION
 		(2nd condition)
 		down one, left two
 		IF YOU HIT ANOTHER FILLED POSITION
			(3rd condition)
 			left two

SOURCE -> https://www.wikiwand.com/en/Siamese_method
*/

int** generateSquare(int side){
	int ** magicSquare = new int*[side];
	for(int i = 0; i < side; i++){
		magicSquare[i] = new int[side];
		for(int j = 0; j < side; j++){
			magicSquare[i][j] = 0;
		}
	}

	int row = side / 2;
	int col = side - 1;

	//BULK OF THE WORK
	for (int num = 1; num <= side * side;) {
		if (row == -1 && col == side){// 3rd condition
			col = side - 2;
			row = 0;
		}else{
			// standard condition
			//OVERFLOW HANDLING
			if (col == side){
				col = 0;
			}
			if (row < 0){
				row = side - 1;
			}
		}
		if (magicSquare[row][col]){//2nd condition
			col -= 2;
			row++;
			continue;
		}else{
			magicSquare[row][col] = num++;
		}
		col++;
		row--;
	}

	return magicSquare;
}

//BAD O(N^2) SOLUTION
int** makeMagicSquare(int side){
	vector<int> a(side*side);
	for(int i = 0; i < side * side; i++){
		a[i] = i + 1;
	}

	while(next_permutation(a.begin(), a.end())){
		int** outArray = new int*[side];
		for(int row = 0; row < side; row++){
			outArray[row] = new int[side];
			for(int col = 0; col < side; col++){
				outArray[row][col] = a[row * side + col];
			}
		}
		if(checkSquare(outArray, side)){
			return outArray;
		}
	}
	return nullptr;
}

int main(){
	//a
	int side = 3;
	int ** a = makeMagicSquare(3);
	for(int row = 0; row < side; row++){
		for(int col = 0; col < side; col++){
			cout << a[row][col] << " ";
		}
		cout << endl;
	}

	//b
	side = 5;
	a = generateSquare(side);
	for (int row = 0; row < side; row++) {
		for (int col = 0; col < side; col++)
			cout << setw(2) << a[row][col] << " ";
		cout << endl;
	}

	//c ➡ done

	//d
	side = 7;
	a = generateSquare(side);
	for (int row = 0; row < side; row++) {
		for (int col = 0; col < side; col++)
			cout << setw(2) << a[row][col] << " ";
		cout << endl;
	}
}