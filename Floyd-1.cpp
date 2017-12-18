//https://www.e-olymp.com/uk/problems/974
#include <iostream>
#include <climits>
#include <fstream>


using namespace std;

long long vector[101][101];

int main() {
	//ifstream in("in.txt");
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int a;
			cin >> a;
			vector[i][j] = a;
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (vector[i][k] + vector[k][j] < vector[i][j]) {
					vector[i][j] = vector[i][k] + vector[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << vector[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}