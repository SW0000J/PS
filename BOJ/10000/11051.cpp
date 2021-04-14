#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int K;
	cin >> N >> K;

	dp[0][0] = 1;
	dp[0][1] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}