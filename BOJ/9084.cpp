#include <iostream>
#include <vector>
#include <algorithm>

int dp[10001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int T; std::cin >> T;

	for (int tc = 0; tc < T; tc++) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;

		int N; std::cin >> N;
		std::vector<int> v(N);

		for (int i = 0; i < N; i++) {
			std::cin >> v[i];
		}

		int M; std::cin >> M;

		for (int i = 0; i < N; i++) {
			for (int j = v[i]; j <= M; j++) {
				dp[j] += dp[j - v[i]];
			}
		}

		std::cout << dp[M] << "\n";
	}

	return 0;
}