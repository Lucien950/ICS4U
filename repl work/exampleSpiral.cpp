#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 6
void spiralPrint(int m, int n, int a[R][C]){
	int k = 0, l = 0;

	/* k - starting row index
		m - ending row index
		l - starting column index
		n - ending column index
	*/

	while (k < m && l < n) {
		//=============Up mode=============
		/* Print the first row from the remaining rows */
		for (int i = l; i < n; ++i) { // i from l to n
			cout << a[k][i] << " ";
		}
		k++;

		/* Print the last column from the remaining columns */
		for (int i = k; i < m; ++i){ // i from k to m
			cout << a[i][n - 1] << " ";
		}
		n--;


		//=============Down mode=============
		/* Print the last row from the remaining rows */
		if (k < m) {
			for (int i = n - 1; i >= l; --i) {// n-1 down to l
				cout << a[m - 1][i] << " ";
			}
			m--;
		}

		/* Print the first column from the remaining columns */
		if (l < n) {
			for (int i = m - 1; i >= k; --i) {//m-1 down to k
				cout << a[i][l] << " ";
			}
			l++;
		}
	}
}
int main()
{
	int a[R][C] = { { 1, 2, 3, 4, 5, 6 },
					{ 7, 8, 9, 10, 11, 12 },
					{ 13, 14, 15, 16, 17, 18 } };

	// Function Call
	spiralPrint(R, C, a);
	return 0;
}