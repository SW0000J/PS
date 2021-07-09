#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 9999999

int V;
int E;
int K;

vector<pair<int, int>> graph[20001];
int ans[20001];

void dijkstra() {
	for (int i = 1; i <= V; i++) {
		ans[i] = INF;
	}
	ans[K] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, K));

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (ans[node] < cost) {
			continue;
		}

		for (int i = 0; i < graph[node].size(); i++) {
			int nextCost = cost + graph[node][i].second;
			int nextNode = graph[node][i].first;

			if (ans[nextNode] > nextCost) {
				ans[nextNode] = nextCost;
				pq.push(make_pair(nextCost, nextNode));
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (i == K) {
			cout << 0 << "\n";
		}
		else if (ans[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << ans[i] << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int a;
		int b;
		int cost;
		cin >> a >> b >> cost;

		graph[a].push_back(make_pair(b, cost));
	}

	dijkstra();

	return 0;
}