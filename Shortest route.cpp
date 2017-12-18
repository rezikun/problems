#include <iostream>
#include <climits>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 10000000

using namespace std;

struct route {
	int from, to, cost;
};

vector<route> routes;

int main() {
	int n, m, from, to;
	//ifstream in("in.txt");
	cin >> n >> m >> from >> to;
	vector<int> distance(n + 1, INF);
	distance[from] = 0;
	vector<int> p(n + 1);
	vector<bool> used(n + 1, false);
	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		route next;
		next.cost = cost;
		next.from = from;
		next.to = to;
		routes.push_back(next);
		next.from = to;
		next.to = from;
		routes.push_back(next);
	}
	for (;;) {
		bool flag = false;
		for (int j = 0; j < 2*m; ++j) {
			if (distance[routes[j].to] > distance[routes[j].from] + routes[j].cost) {
				distance[routes[j].to] = distance[routes[j].from] + routes[j].cost;
				p[routes[j].to] = routes[j].from;
				flag = true;
			}
		}
		if (!flag)
			break;
	}
	if (distance[to] == INF) {
		cout << -1;
		return 0;
	}
	cout << distance[to] << endl;
	vector<int> ans;
	int start = to;
	ans.push_back(to);
	while (start != from) {
		start = p[start];
		ans.push_back(start);
	}
	for (int i = ans.size() - 1; i >= 0; --i) {
		cout << ans[i] << " ";
	}
	return 0;
}