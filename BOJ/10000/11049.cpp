#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

int matrix[501][2];
int dp[501][501];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> matrix[i][0] >> matrix[i][1];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; i + j <= N; j++) {
			dp[j][i + j] = INT_MAX;

			for (int k = j; k <= i + j; k++) {
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j][0] * matrix[k][1] * matrix[i + j][1]);
			}
		}
	}

	cout << dp[1][N] << "\n";

	return 0;
}