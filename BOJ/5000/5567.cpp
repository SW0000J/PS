#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int m;
vector<int> graph[501];
bool visit[501];
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a;
		int b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	visit[1] = true;

	vector<int> friendVec(graph[1].size());
	for (int i = 0; i < graph[1].size(); i++) {
		friendVec[i] = graph[1][i];
		visit[friendVec[i]] = true;
		ans++;
	}

	for (int i = 0; i < friendVec.size(); i++) {
		for (int j = 0; j < graph[friendVec[i]].size(); j++) {
			if (!visit[graph[friendVec[i]][j]]) {
				visit[graph[friendVec[i]][j]] = true;
				ans++;
			}
		}
	}

	cout << ans << "\n";

	return 0;
}