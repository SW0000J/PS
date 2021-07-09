#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][10];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = j; k <= 9; k++) {
				dp[i][k] += dp[i - 1][j];
				dp[i][k] %= 10007;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i <= 9; i++) {
		ans += dp[N][i];
	}
	
	cout << ans % 10007 << "\n";

	return 0;
}