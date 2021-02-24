#include <iostream>
#include <vector>
#include <algorithm>

int dp[16] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<std::pair<int, int>> v(N + 1);

	for (int i = 1; i <= N; i++) {
		std::cin >> v[i].first >> v[i].second;
	}

	for (int i = N; i >= 1; i--) {
		if (i + v[i].first > N + 1) {
			dp[i] = dp[i + 1];
			continue;
		}

		dp[i] = std::max(dp[i + v[i].first] + v[i].second, dp[i + 1]);
	}

	std::cout << dp[1] << "\n";

	return 0;
}

// fail code
/*
	for (int i = 1; i <= N; i++) {
		if (i + v[i].first > N + 1) {
			dp[i] = dp[i - 1];
			continue;
		}

		dp[i] = std::max(dp[i - v[i].first] + v[i].second, dp[i] + v[i].second);
	}
*/