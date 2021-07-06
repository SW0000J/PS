#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int N;
int M;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

string arr[100];
int ans[100][100];
bool visit[100][100];

void bfs(int i, int j) {
	visit[i][j] = true;
	
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && arr[ny][nx] == '1' && !visit[ny][nx] && ans[ny][nx] == 0) {
				visit[ny][nx] = true;
				ans[ny][nx] = ans[y][x] + 1;

				q.push(make_pair(ny, nx));
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
		cin >> arr[i];
	}

	bfs(0, 0);

	cout << ans[N - 1][M - 1] + 1 << "\n";

	return 0;
}