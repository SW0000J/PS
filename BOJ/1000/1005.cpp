#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int buildTime[1001];
vector<int> buildRule[1001];
int ans[1001];
int buildDelay[1001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		memset(buildTime, 0, sizeof(buildTime));
		memset(ans, 0, sizeof(ans));
		memset(buildDelay, 0, sizeof(buildDelay));
		for (int i = 0; i < 1001; i++) {
			buildRule[i].clear();
		}

		int N;
		int K;
		cin >> N >> K;

		for (int i = 1; i <= N; i++) {
			cin >> buildTime[i];
		}

		for (int i = 0; i < K; i++) {
			int x;
			int y;
			cin >> x >> y;

			buildRule[x].push_back(y);
			buildDelay[y]++;
		}

		int W; cin >> W;
		queue<int> q;

		for (int i = 1; i <= N; i++) {
			if (buildDelay[i] == 0) {
				q.push(i);
				ans[i] = buildTime[i];
			}
		}

		while (!q.empty()) {
			int num = q.front();
			q.pop();

			for (int i = 0; i < buildRule[num].size(); i++) {
				int nextNum = buildRule[num][i];

				ans[nextNum] = max(ans[nextNum], ans[num] + buildTime[nextNum]);
				buildDelay[nextNum]--;

				if (buildDelay[nextNum] == 0) {
					q.push(nextNum);
				}
			}
		}

		cout << ans[W] << "\n";
	}

	return 0;
}