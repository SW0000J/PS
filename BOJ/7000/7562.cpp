#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

bool visited[300][300];

std::pair<int, int> start;
std::pair<int, int> end;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

void bfs(int a, int b, int size) {
	visited[a][b] = true;

	// pair -> <<x, y> pair, time>
	std::queue<std::pair<std::pair<int, int>, int>> q;
	q.push(std::make_pair(std::make_pair(a, b), 0));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();

		if (x == end.first && y == end.second) {
			std::cout << time << "\n";
			return;
		}
		else {
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= size || ny < 0 || ny >= size) {
					continue;
				}
				else if (!visited[nx][ny]) {
					visited[nx][ny] = true;

					q.push(std::make_pair(std::make_pair(nx, ny), time + 1));
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int T; std::cin >> T;

	for (int tc = 0; tc < T; tc++) {
		memset(visited, 0, sizeof(visited));

		int l; std::cin >> l;

		std::cin >> start.first >> start.second;
		std::cin >> end.first >> end.second;

		bfs(start.first, start.second, l);
	}

	return 0;
}