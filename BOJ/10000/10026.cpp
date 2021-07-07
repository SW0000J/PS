#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int N;
char arr[100][100];
bool visit[100][100];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(int i, int j) {
	visit[i][j] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visit[nx][ny] && arr[nx][ny] == arr[x][y]) {
				visit[nx][ny] = true;

				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	int sickAns = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				bfs(i, j);
				ans++;
			}
		}
	}

	memset(visit, false, sizeof(visit));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 'G') {
				arr[i][j] = 'R';
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				bfs(i, j);
				sickAns++;
			}
		}
	}

	cout << ans << " " << sickAns << "\n";

	return 0;
}