#include <iostream>
#include <cstring>
using namespace std;

int arr[50][50];
bool visited[50][50];

int dx[8] = { 0, 1, -1, 0, 1, -1, -1, 1 };
int dy[8] = { 1, 0, 0, -1, -1, 1, -1, 1 };

void dfs(const int& maxX, const int& maxY, int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < maxX && ny < maxY) {
			if (!visited[nx][ny] && arr[nx][ny] == 1) {
				visited[nx][ny] = true;
				dfs(maxX, maxY, nx, ny);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	while (true) {
		int w;
		int h;
		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}

		int ans = 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && arr[i][j] == 1) {
					dfs(h, w, i, j);
					ans++;
				}
			}
		}

		cout << ans << "\n";

		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}