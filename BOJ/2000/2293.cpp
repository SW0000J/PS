#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	int k;
	cin >> n >> k;

	vector<int> v(n);
	vector<int> dp(k + 1);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = v[i]; j <= k; j++) {
			dp[j] += dp[j - v[i]];
//			cout << dp[j] << " ";
		}
//		cout << "\n";
	}

	cout << dp[k] << "\n";

	return 0;
}