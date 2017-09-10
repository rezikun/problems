#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int fat(int n) {
	int res = 1;
	for (int i = 2; i <= n; ++i)
		res *= i;
	return res;
}

int bin_search(int x) {
	int left = 2;
	int right = 1000000000;
	int mid = (left + right) / 2;
	while (right - left > 1) {
		long long a = log10(sqrt(2 * acos(-1)*mid)) + mid*log10(mid / exp(1)) + 1;
		if (a == x)
			break;
		if (a > x) {
			right = mid;
			mid = (left + right) / 2;
		}
		else {
			left = mid;
			mid = (left + right) / 2;
		}
	}
	--mid;
	long long a = log10(sqrt(2 * acos(-1)*mid)) + mid*log10(mid / exp(1)) + 1;
	while (a <= x) {
		++mid;
		a = log10(sqrt(2 * acos(-1)*mid)) + mid*log10(mid / exp(1)) + 1;
	}
	return mid - 1;
}

int main() {

	int mid = 9;
	double pi = acos(-1);
	long long a = log10(sqrt(2 * acos(-1)*mid)) + mid*log10(mid / exp(1)) + 1;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		if (n > 3) {
			long long a = bin_search(n);
			printf("%lld\n", a);
		}
		else {
			int fact = 1;
			int i = 2;
			while (int(log10(fat(i))) + 1 <= n)
				++i;
			printf("%d\n", i - 1);
		}
	}
	return 0;
}