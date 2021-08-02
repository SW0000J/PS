#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

const int INF = INT_MAX;

vector<pair<int, int>> graph[10001];
vector<int> dp;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int D;
	cin >> N >> D;

	dp.resize(D + 1, INF);
	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		int start;
		int end;
		int shortCut;
		cin >> start >> end >> shortCut;

		graph[end].push_back(make_pair(start, shortCut));
	}

	for (int i = 1; i <= D; i++) {
		if (!graph[i].empty()) {
			for (auto elem : graph[i]) {
				dp[i] = min(dp[i], min(dp[elem.first] + elem.second, dp[i - 1] + 1));
			}
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	cout << dp[D] << "\n";

	return 0;
}