#include <iostream>
#include <random>
#include <math.h>
using namespace std;

int power(int base, int exponent){
	if(exponent == 1){
		return base;
	}
	return base * power(base, exponent - 1);
}

int fib(int n){
	if(n == 1 || n == 2){
		return 1;
	}
	return fib(n-1) + fib(n-2);
}

void printArrayRecursive(int a[], int max, int n = 0){
	if(n == max){
		return;
	}
	cout << a[n] << " ";
	printArrayRecursive(a, max, n+1);
}

int* init_array(){
	int* out = new int[10];
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<> dist(1,10);
	for(int i = 0; i < 10; i++){
		out[i] = dist(mt);
	}
	return out;
}

int* twoPower(int n, int runningVal = 1, int runningIter = 1, int* returner = nullptr){
	if(runningIter == 1){
		returner = new int[n];
	}
	returner[runningIter - 1] = runningVal;
	if(runningIter == n){
		return returner;
	}
	return twoPower(n, runningVal * 2, runningIter + 1, returner);
}

int sumArray(const int arr[], int arrSize){
	int sum = 0;
	for(int i = 0; i < arrSize; i++){
		sum += arr[i];
	}
	return sum;
}

int recursive_sum(const int arr[], int arrSize, int i = 0){
	if(i == arrSize){
		return 0;
	}
	return arr[i] + recursive_sum(arr, arrSize, i+1);
}

int maxVal(const int arr[], int arrSize){
	int out = arr[0];
	for(int i = 0; i < arrSize; i++){
		if(arr[i] > out){
			out = arr[i];
		}
	}
	return out;
}

int recursive_largest(const int arr[], int arrSize, int i = 0){
	if(i == arrSize-1){
		return arr[i];
	}

	int next = recursive_largest(arr, arrSize, i+1);
	if(arr[i] > next){
		return arr[i];
	}else{
		return next;
	}
};

double birthdayMatch(int people){
	double top = 1;
	for(int i = 0; i < people; i++){
		top *= 365-i;
	}
	return 100.0*(1.0 - (top/pow(365, people)));
};

double birthdayMatch_rec(int people, int i = 1){
	if(i == people && i == 1){
		return 0;
	}
	else if(i == people){
		return ((366-i)/(365.0));
	}
	else if(i == 1){
		return 100.0 * (1 - (((366-i)/(365.0)) * birthdayMatch_rec(people, i + 1)));
	}
	else{
		return ((366-i)/(365.0)) * birthdayMatch_rec(people, i + 1);
	}
}

int main(){
	//EXAMPLE 1
	cout << power(2, 3) << endl;

	//EXAMPLE 2
	cout << fib(10) << endl;

	//EXAMPLE 3
	int a[4] = {1, 2, 3, 4};
	printArrayRecursive(a, 4);
	cout << endl;

	//EXAMPLE 4
	//a)
	int* randArray = init_array();
	//b)
	int* twoPowers = twoPower(5);
	//c)
	int sum = sumArray(a, 4);
	cout << sum << endl;
	//d)
	int recurSum = recursive_sum(a,4 );
	cout << recurSum << endl;
	//e)
	int max = maxVal(a, 4);
	cout << max << endl;
	//f)
	int maxRecur = recursive_largest(a, 4);
	cout << maxRecur << endl;

	//EXAMPLE 5
	cout << birthdayMatch(1) << "%" << endl;
	cout << birthdayMatch(2) << "%" << endl;
	cout << birthdayMatch(26) << "%" << endl;

	cout << birthdayMatch_rec(1) << "%" << endl;
	cout << birthdayMatch_rec(2) << "%" << endl;
	cout << birthdayMatch_rec(26) << "%" << endl;

}