#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int m;
vector<int> graph[501];
bool visit[501];

bool dfs(int node, int beforeNode) {
	visit[node] = true;

	for (auto nextNode : graph[node]) {
		if (nextNode == beforeNode) {
			continue;
		}

		if (visit[nextNode] || !dfs(nextNode, node)) {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int caseCount = 0;

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0) {
			break;
		}

		int treeNum = 0;
		memset(visit, false, sizeof(visit));

		for (int i = 0; i <= n; i++) {
			graph[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int u;
			int v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (!visit[i] && dfs(i, 0)) {
				treeNum++;
			}
		}

		cout << "Case " << ++caseCount;
		if (treeNum == 0) {
			cout << ": No trees.\n";
		}
		else if (treeNum == 1) {
			cout << ": There is one tree.\n";
		}
		else {
			cout << ": A forest of " << treeNum << " trees.\n";
		}
	}

	return 0;
}