//https://www.e-olymp.com/en/problems/1365
#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 30000

using namespace std;

int matrix[101][101];

int main() {
	int n, from, to;
	//ifstream in("in.txt");
	cin >> n >> from >> to;
	vector<int> distance(n + 1, INF);
	distance[from - 1] = 0;
	vector<bool> used(n + 1, false);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		int next = -1;
		for (int j = 0; j < n; ++j) {
			if (used[j] != true && (next == -1 || distance[j] < distance[next])) {
				next = j;
			}
		}
		if (distance[next] == INF)
			break;
		used[next] = true;
		for (int k = 0; k < n; ++k) {
			if(matrix[next][k] != -1)
				distance[k] = min(distance[k], distance[next] + matrix[next][k]);
		}
	}
if(distance[to - 1] == INF)
cout << -1;
else
	cout << distance[to - 1];
	return 0;
}