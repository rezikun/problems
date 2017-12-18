#include <stdio.h>
#include <cmath>
#include <algorithm>

using namespace std;


int dp[1001][1001];

int main() {
	const int inf = 1000000;
	for (int i = 0; i < 1001; ++i) {
		dp[1][i] = i;
	}
	for (int i = 2; i < 1001; ++i) {
		int k = 1;
		for (int j = 1; j < 1001; ++j) {
			if (j == 11)
				int a = 1;
			int m = inf;
			--k;
			for (; k <= j / 2 + 1; ++k) {
				int crashed = dp[i - 1][k - 1] + 1;
				int not_crashed = dp[i][j - k] + 1;
				if (m >= max(crashed, not_crashed))
					m = max(crashed, not_crashed);
				else
					break;
			}
			dp[i][j] = m;
		}
	}
 	while (1) {
		int eggs, floor;
		scanf("%d%d", &eggs, &floor);
		if (eggs == 0 && floor == 0)
			break;
		printf("%d\n", dp[eggs][floor]);
	}
	return 0;
}