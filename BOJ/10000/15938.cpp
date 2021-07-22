#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>
#include <limits.h>
using namespace std;

const int mod = 1000000007;

int startX;
int startY;
int T;
int homeX;
int homeY;
int N;

int dp[401][401][201];
map<pair<int, int>, bool> visit;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dfs(int x, int y, int s) {
	int nowX = startX + x;
	int nowY = startY + y;

	if (nowX == homeX && nowY == homeY) {
		return 1;
	}

	if (T == s) {
		return 0;
	}

	if (abs(homeX - nowX) + abs(homeY - nowY) > T - s) {
		return 0;
	}

	if (dp[x + 200][y + 200][s] != -1) {
		return dp[x + 200][y + 200][s];
	}

	dp[x + 200][y + 200][s] = 0;

	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i];
		int newY = y + dy[i];

		nowX = startX + newX;
		nowY = startY + newY;

		if (!visit[make_pair(nowX, nowY)]) {
			dp[x + 200][y + 200][s] = (dp[x + 200][y + 200][s] + dfs(newX, newY, s + 1) % mod) % mod;
		}
	}

	return dp[x + 200][y + 200][s];
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	memset(dp, -1, sizeof(dp));

	cin >> startX >> startY;
	cin >> T;
	cin >> homeX >> homeY;
	cin >> N;

	startX += 100000;
	startY += 100000;
	homeX += 100000;
	homeY += 100000;

	for (int i = 0; i < N; i++) {
		int x;
		int y;
		cin >> x >> y;

		x += 100000;
		y += 100000;

		visit[make_pair(x, y)] = true;
	}

	cout << dfs(0, 0, 0) << "\n";

	return 0;
}