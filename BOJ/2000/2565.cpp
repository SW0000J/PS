#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int dp[100];
vector<pair<int, int>> v;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int A;
		int B;
		cin >> A >> B;

		v.push_back(make_pair(A, B));
	}

	sort(v.begin(), v.end());

	int lis = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = 1;

		for (int j = 0; j < i; j++) {
			if (v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}

			lis = max(lis, dp[i]);
		}
	}

	cout << N - lis << "\n";

	return 0;
}