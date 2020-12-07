#include <iostream>
#include <numeric>

using namespace std;

int * func1(int n, int i = 0, int* a = nullptr){
	if(a == nullptr){
		a = new int[n];
		a[0] = 3;
		return func1(n, i+1, a);
	}

	a[i] = a[i-1] - 2;
	if(i == n){
		return a;
	}

	return func1(n, i+1, a);
}

int * func2(int n, int i = 0, int* a = nullptr){
	if(a == nullptr){
		a = new int[n];
		a[0] = -1;
		return func2(n, i+1, a);
	}

	a[i] = 2*a[i-1];
	if(i == n){
		return a;
	}

	return func2(n, i+1, a);
}

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}
int lcm(int a, int b)
{
	int temp = gcd(a, b);

	return temp ? (a / temp * b) : 0;
}

void reverse(string &str, int i = 0){
	static int k = 0;

	if(i == str.length()){
		return;
	}

	reverse(str, i + 1);

	if (k <= i){
		swap(str[k++], str[i]);
	}
}

bool isPalindrome(string str, int start = 0, int end = 0){
	if(end == 0){
		end = str.length()-1;
	}

	if(start == end){
		return true;
	}

	if(str[start] != str[end]){
		return false;
	}

	if(start < end + 1){
		return isPalindrome(str, start + 1, end - 1);
	}
	return true;
}

string decimalToBinary(int a){
	if (a == 0) {
		return "0";
	}
	else{
		return to_string((a % 2 + 10 * stoi(decimalToBinary(a / 2))));
	}
}

float averageArray(int A[],int n){
	if(n==0){
		return A[n - 1];
	}
	else{
		return ( A[n - 1] + (n-1)*averageArray(A,n-1) ) / n;
	}
}

int fractorial(int l, int i = -1){
	if(i == -1){
		i = l;
	}
	if(i == 1){
		return 1;
	}
	return lcm(i, fractorial(l, i - 1));
}


void printArr(int * a, int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << endl;
	}
}

int main(){
	//1
	//a
	int n = 5;
	int * a = func1(n);
	printArr(a, n);
	//b
	a = func2(n);
	printArr(a, n);

	//2
	int x = 10, y=12;
	int low = gcd(x, y);
	cout << low << endl;

	//3
	//a
	string str1 = "abcd";
	reverse(str1);
	cout << str1 << endl;

	//b
	string str2 = "abcba";
	cout << str2 << " ";
	if(isPalindrome(str2)){
		cout << "is a palindrome" << endl;
	}else{
		cout << "not a palindrome" << endl;
	}

	//4
	int num = 10;
	cout << decimalToBinary(num) << endl;

	//5
	int numList[] = {1, 2, 3, 4, 5};
	cout << averageArray(numList, 5) << endl;

	//6
	cout << fractorial(8) << endl;
}