#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N;
int M;
int board[101];
int ans[101];

void bfs() {
	queue<int> q;

	q.push(1);
	ans[1] = 0;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nx = x + i;

			if (nx > 100) {
				break;
			}

			if (board[nx] != 0) {
				nx = board[nx];
			}

			if (ans[nx] == -1) {
				ans[nx] = ans[x] + 1;
				q.push(nx);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x;
		int y;
		cin >> x >> y;

		board[x] = y;
	}

	for (int i = 0; i < M; i++) {
		int u;
		int v;
		cin >> u >> v;

		board[u] = v;
	}

	memset(ans, -1, sizeof(ans));

	bfs();

	cout << ans[100] << "\n";

	return 0;
}