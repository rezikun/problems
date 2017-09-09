#include <stdio.h>
#include <vector>

using namespace std;

int prost[4000000];

void erat() {
	for (int i = 2; i < 4000000; ++i) {
		if (prost[i] == 0) {
			for (int j = i + i; j < 4000000; j += i) {
				prost[j] = 1;
			}
		}
	}
}
vector<int> sum;
void TheSum() {
	sum.push_back(0);
	for (int i = 1; i < 1001000; ++i) {
		if (prost[3 * i + 7] == 0) 
			sum.push_back(sum[i - 1] + 1);
		else
			sum.push_back(sum[i - 1]);
	}
}

int main() {
	erat();
	TheSum();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		printf("%ld\n", sum[n]);
	}
	return 0;
}