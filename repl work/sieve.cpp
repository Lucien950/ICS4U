#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int main(){
	cout << "How many prime numbers do you want?" << endl;

	int sieveSize;
	cin >> sieveSize;

	int sieve[sieveSize];
	fill_n(sieve, sieveSize + 1, 1);
	for(int i = 2; i <= ceil(sieveSize/2); i++){
		int badNum = i + i;
		while(badNum <= sieveSize){
			sieve[badNum] = 0;
			badNum += i;
		}
	}

	for(int i = 2; i < sieveSize + 1; i++){
		if(sieve[i] == 1){
			cout << i << endl;
		}
	}

	return 0;
}