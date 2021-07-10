#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int V;
vector<pair<int, int>> tree[100001];
bool visit[100001];
int maxNode = 0;
int maxDist = 0;

void dfs(int node, int dist) {
	if (visit[node]) {
		return;
	}

	visit[node] = true;

	if (maxDist < dist) {
		maxDist = dist;
		maxNode = node;
	}

	for (int i = 0; i < tree[node].size(); i++) {
		int nextNode = tree[node][i].first;
		int nextDist = tree[node][i].second;

		dfs(nextNode, dist + nextDist);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> V;

	for (int i = 1; i <= V; i++) {
		int num;
		int vNum1;
		int vNum2;
		cin >> num >> vNum1;

		while (vNum1 != -1) {
			cin >> vNum2;

			tree[num].push_back(make_pair(vNum1, vNum2));
			tree[vNum1].push_back(make_pair(num, vNum2));

			cin >> vNum1;
		}
	}

	dfs(1, 0);

	memset(visit, false, sizeof(visit));
	maxDist = 0;

	dfs(maxNode, 0);

	cout << maxDist << "\n";

	return 0;
}