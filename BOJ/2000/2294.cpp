#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[10001];
int coin[101];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	int k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= k; i++) {
		dp[i] = 9999999;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 9999999) {
		cout << -1 << "\n";
	}
	else {
		cout << dp[k] << "\n";
	}

	return 0;
}