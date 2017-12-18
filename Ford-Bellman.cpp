//https://www.e-olymp.com/uk/problems/1453
#include <iostream>
#include <climits>
#include <fstream>
#include <vector>

#define INF 30000

using namespace std;

struct route {
	int from, to, cost;
};

vector<route>  routes;

int main() {
	int n, m;
	//ifstream in("in.txt");
	cin >> n >> m;
	vector<int> d(n+1, INF);
	for (int i = 0; i < m; ++i) {
		route a;
		cin >> a.from >> a.to >> a.cost;
		routes.push_back(a);
	}
	d[1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (d[routes[j].from] != INF) {
				d[routes[j].to] = d[routes[j].to] > d[routes[j].from] + routes[j].cost ? d[routes[j].from] + routes[j].cost : d[routes[j].to];
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << d[i] << " ";
	}
	return 0;
}