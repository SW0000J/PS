#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	dp[1] = 1;
	dp[2] = 3;
	
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	}

	cout << dp[N] << "\n";

	return 0;
}