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
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<> dist(1,10);
void init_array(int * arr, int size){
	if(size == 0){
		return;
	}
	arr[size-1] = dist(mt);
	return init_array(arr, size - 1);
}

void twoPower(int* arr, int size){
	if(size == -1){
		return;
	}
	arr[size-1] = pow(2, size-1);
	return twoPower(arr, size - 1);
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

int recursive_largest(const int arr[], int size){
	if(size == 0){
		return arr[size];
	}
	return max(arr[size-1], recursive_largest(arr, size - 1));
}

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
	cout << "Power" << endl;
	cout << power(2, 3) << endl << endl;

	//EXAMPLE 2
	cout << "Fibinocci" << endl;
	cout << fib(10) << endl << endl;

	//EXAMPLE 3
	cout<<"Print Recursively" << endl;
	int a[4] = {1, 2, 3, 4};
	printArrayRecursive(a, 4);
	cout << endl << endl;

	//EXAMPLE 4
	//a)
	cout << "Random Array" << endl;
	int* randArray = new int[10];
	init_array(randArray, 10);
	printArrayRecursive(randArray, 10);
	cout << endl << endl;
	//b)
	int * arr = new int[5];
	twoPower(arr, 5);
	cout << "TWO POWERS" << endl;
	for(int i = 0; i < 5; i++){
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	//c)
	cout << "Sum" << endl;
	int sum = sumArray(a, 4);
	cout << sum << endl;
	//d)
	cout << "Recursive Sum" << endl;
	int recurSum = recursive_sum(a,4 );
	cout << recurSum << endl << endl;
	//e)
	cout << "Max Value" << endl;
	int max = maxVal(a, 4);
	cout << max << endl;
	//f)
	cout << "Recursive Largest" << endl;
	int maxRecur = recursive_largest(a, 4);
	cout << maxRecur << endl << endl;

	//EXAMPLE 5
	cout << birthdayMatch(1) << "%" << endl;
	cout << birthdayMatch(2) << "%" << endl;
	cout << birthdayMatch(26) << "%" << endl;

	cout << birthdayMatch_rec(1) << "%" << endl;
	cout << birthdayMatch_rec(2) << "%" << endl;
	cout << birthdayMatch_rec(26) << "%" << endl;

}