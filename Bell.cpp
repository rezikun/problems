//https://www.e-olymp.com/en/problems/2329
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int a[35000];
int a2[35000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {	
		cin >> a[i];
	}
	int count = 1;
	sort(a, a + n);
	int j = 0, jj = 0;
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			a2[j] = a[i];
			++j;
		}
		else {
			a2[n - jj - 1] = a[i];
			++jj;
		}
	}
	for (int i = 0; i < n; ++i)
		cout << a2[i] << " ";
	cout << endl;
	return 0;
}