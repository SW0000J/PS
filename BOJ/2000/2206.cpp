#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int N;
int M;

int map[1001][1001];
int root[1001][1001][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 1));
	root[1][1][1] = 1;

	while (!q.empty()) {
		int x = q.front().first.second;
		int y = q.front().first.first;
		int wall = q.front().second;
		q.pop();

		if (x == M && y == N) {
			return root[y][x][wall];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > 0 && nx <= M && ny > 0 && ny <= N) {
				if (map[ny][nx] == 0 && root[ny][nx][wall] == 0) {
					root[ny][nx][wall] = root[y][x][wall] + 1;
					q.push(make_pair(make_pair(ny, nx), wall));
				}

				if (map[ny][nx] == 1 && wall == 1) {
					root[ny][nx][wall - 1] = root[y][x][wall] + 1;
					q.push(make_pair(make_pair(ny, nx), wall - 1));
				}
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string buf; cin >> buf;

		for (int j = 1; j <= M; j++) {
			map[i][j] = buf[j - 1] - '0';
		}
	}

	cout << bfs() << "\n";

	return 0;
}