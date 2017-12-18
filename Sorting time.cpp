//https://www.e-olymp.com/en/problems/972
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;



struct Triple {
	int hh, mm, ss;
};

Triple a[10000];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {	
		cin >> a[i].hh >> a[i].mm >> a[i].ss;
	}
	int count = 1;
	for (; count != 0;) {
		count = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i - 1].hh > a[i].hh) {
				swap(a[i - 1], a[i]);
				++count;
			}		
		}
		for (int i = 1; i < n; ++i) {
			if (a[i - 1].hh == a[i].hh && a[i - 1].mm > a[i].mm) {
				swap(a[i - 1], a[i]);
				++count;
			}
		}
		for (int i = 1; i < n; ++i) {
			if (a[i - 1].hh == a[i].hh && a[i - 1].mm == a[i].mm && a[i - 1].ss > a[i].ss) {
				swap(a[i - 1], a[i]);
				++count;
			}
		}
	}
		for (int i = 0; i < n; ++i)
			cout << a[i].hh << " " << a[i].mm << " " << a[i].ss << endl;
	return 0;
}