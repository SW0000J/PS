#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[100][100][100];
queue< pair<pair<int, int>, int>> q;

int dx[6] = { 0, 0, 1, -1, 0, 0 };
int dy[6] = { 1, -1, 0, 0, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

int ans = 0;

bool checkTomato(const int& a, const int& b, const int& c) {
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < b; j++) {
			for (int k = 0; k < a; k++) {
				if (arr[j][k][i] == 0) {
					return false;
				}
			}
		}
	}

	return true;
}

void bfs(const int& a, const int& b, const int& c) {
	while (!q.empty()) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int h = q.front().second;
			q.pop();

			for (int j = 0; j < 6; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				int nh = h + dh[j];

				// std::cout << nx << " " << ny << " " << nh << "\n";

				if (nx >= 0 && ny >= 0 && nh >= 0 && nx < b && ny < a && nh < c) {
					if (arr[nx][ny][nh] == 0) {
						arr[nx][ny][nh] = 1;
						q.push(make_pair(make_pair(nx, ny), nh));
					}
				}
			}

			if (q.size() == 0) {
				if (checkTomato(a, b, c)) {
					cout << ans << "\n";
					return;
				}
				else {
					cout << -1 << "\n";
					return;
				}
			}
		}

		ans++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int M;
	int N;
	int H;
	cin >> M >> N >> H;

	bool isripe = true;
	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> arr[j][k][i];
				
				if (arr[j][k][i] == 0) {
					isripe = false;
				}
				
				if (arr[j][k][i] == 1) {
					q.push(make_pair(make_pair(j, k), i));
				}
			}
		}
	}

	if (isripe) {
		cout << 0 << "\n";
	}
	else {
		bfs(M, N, H);
	}

	return 0;
}