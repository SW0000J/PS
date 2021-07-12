#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 999999999

int n;
int m;
int cost[101][101];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cost[i][j] = INF;
		}
	}

	for (int i = 0; i <= n; i++) {
		cost[i][i] = 0;
	}

	for (int i = 0; i < m; i++) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;

		cost[a][b] = min(cost[a][b], c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cost[i][j] == INF) {
				cout << 0 << ' ';
			}
			else {
				cout << cost[i][j] << ' ';
			}
		}
		cout << "\n";
	}

	return 0;
}