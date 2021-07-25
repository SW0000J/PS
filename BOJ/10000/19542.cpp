#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int S;
int D;
vector<int> nodeV[100001];
vector<bool> visit;
vector<int> countV;

int ans = 0;

int dfsMax(int node) {
	int maxCount = 0;

	for (auto nextNode : nodeV[node]) {
		if (!visit[nextNode]) {
			visit[nextNode] = true;

			maxCount = dfsMax(nextNode);
			countV[node] = max(countV[node], maxCount);
		}
	}

	return max(countV[node], maxCount) + 1;
}

void dfsAns(int node) {
	for (auto nextNode : nodeV[node]) {
		if (countV[nextNode] >= D && !visit[nextNode]) {
			visit[nextNode] = true;

			ans++;
			dfsAns(nextNode);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> S >> D;

	visit.resize(N + 1);
	countV.resize(N + 1);

	for (int i = 0; i < N - 1; i++) {
		int x;
		int y;
		cin >> x >> y;

		nodeV[x].push_back(y);
		nodeV[y].push_back(x);
	}

	visit[S] = true;
	dfsMax(S);

	fill(visit.begin(), visit.end(), false);

	visit[S] = true;
	dfsAns(S);

	cout << 2 * ans << "\n";

	return 0;
}