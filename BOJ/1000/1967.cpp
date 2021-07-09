#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n;
int maxIndex = 1;
int maxLength = 0;

vector<pair<int, int>> tree[10001];
bool visit[10001];

void dfs(int index, int length) {
	visit[index] = true;

	if (maxLength < length) {
		maxLength = length;
		maxIndex = index;
	}

	for (auto& next : tree[index]) {
		if (!visit[next.first]) {
			visit[next.first] = true;
			dfs(next.first, next.second + length);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i < n; i++) {
		int parent;
		int child;
		int weight;
		cin >> parent >> child >> weight;

		tree[parent].push_back(make_pair(child, weight));
		tree[child].push_back(make_pair(parent, weight));
	}

	dfs(1, 0);

	memset(visit, false, sizeof(visit));

	dfs(maxIndex, 0);

	cout << maxLength << "\n";

	return 0;
}