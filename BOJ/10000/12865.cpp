#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[101][100001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int K;
	cin >> N >> K;

	vector<int> wVector(N + 1);
	vector<int> vVector(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> wVector[i] >> vVector[i];
	}

	for (int i = 1; i <= N; i++) {
		int w = wVector[i];
		int v = vVector[i];

		for (int j = 0; j <= K; j++) {
			if (wVector[i] > j) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
			}
		}
	}

	cout << dp[N][K] << "\n";

	return 0;
}