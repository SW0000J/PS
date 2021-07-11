#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 999999999;

int N;
int M;
int W;
vector<pair<int, int>> graph[501];
int dist[501];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		memset(dist, 999999999, sizeof(dist));
		for (int i = 0; i < 501; i++) {
			graph[i].clear();
		}
		dist[1] = 0;

		cin >> N >> M >> W;

		for (int i = 1; i <= N; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < M; i++) {
			int S;
			int E;
			int T;
			cin >> S >> E >> T;

			graph[S].push_back(make_pair(E, T));
			graph[E].push_back(make_pair(S, T));
		}

		for (int i = 0; i < W; i++) {
			int S;
			int E;
			int T;
			cin >> S >> E >> T;

			graph[S].push_back(make_pair(E, -T));
		}

		bool canCycle = false;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < graph[j].size(); k++) {
					int node = graph[j][k].first;
					int distance = graph[j][k].second;

					if (dist[j] + distance < dist[node]) {
						dist[node] = dist[j] + distance;

						if (i == N) {
							canCycle = true;
						}
					}
				}
			}
		}

		if (canCycle) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}