#include <iostream>
#include <algorithm>
using namespace std;

const int mod = 1000000003;
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 4; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % mod;
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}