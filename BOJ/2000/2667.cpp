#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int arr[25][25];
bool visited[25][25];

int lineCount;

void dfs(int x, int y, const int& size) {
	visited[x][y] = true;
	lineCount++;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= size || ny < 0 || ny >= size) {
			continue;
		}

		if (!visited[nx][ny] && arr[nx][ny] == 1) {
			dfs(nx, ny, size);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<int> ans;

	for (int i = 0; i < N; i++) {
		std::string s; std::cin >> s;

		for (int j = 0; j < N; j++) {
			arr[i][j] = (int)s[j] - 48;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && arr[i][j] == 1) {
				lineCount = 0;

				dfs(i, j, N);

				ans.push_back(lineCount);
			}
		}
	}

	std::sort(ans.begin(), ans.end());

	std::cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << "\n";
	}

	return 0;
}