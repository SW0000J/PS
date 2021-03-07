#include <iostream>
using namespace std;

int arr[1025][1025];
int dp[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int ans = 0;
		int x1;
		int y1;
		int x2;
		int y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j <= x2; j++) {
			ans += dp[j][y2] - dp[j][y1 - 1];
		}

		cout << ans << "\n";
	}

	return 0;
}