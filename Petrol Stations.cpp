#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 10000000

using namespace std;

int matrix[101][101];

void lol() {
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 101; ++j)
			matrix[i][j] = INF;
}

int main() {
	int n;
	//ifstream in("in.txt");
	cin >> n;
	lol();
	vector<int> distance(n + 1, INF);
	vector<int> fuel(n + 1);
	vector<bool> used(n + 1, false);
	distance[1] = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> fuel[i];
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int from, to;
		cin >> from >> to;
		matrix[from][to] = fuel[from];
		matrix[to][from] = fuel[to];
	}
	for (int i = 0; i < n; ++i) {
		int next = -1;
		for (int j = 1; j <= n; ++j) {
			if (!used[j] && (next == -1 || distance[next] > distance[j])) {
				next = j;
			}
		}
		used[next] = true;
		if (distance[next] == INF)
			break;
		for (int k = 1; k <= n; ++k) {
			distance[k] = min(distance[k], distance[next] + matrix[next][k]);
		}
	}

	if (distance[n] == INF)
		cout << -1;
	else
		cout << distance[n];
	return 0;
}