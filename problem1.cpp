#include <iostream>
#include <algorithm>

using namespace std;

int factor(int a){
	long long number = 1;
	for (long long i = 2; i*i <= a; ++i){
		int count = 0;
		while (a % i == 0){
			a /= i;
			++count;
		}
		number *= (count + 1);

	}
	if (a > 1) number *= 2;
	return number;
}

int main(){
	int a, b;
	cin >> a >> b;
	int m = 0;
	for (int i = a; i <= b; ++i){
		m = max(m, factor(i));
	}
	cout << m;
	return 0;
}
