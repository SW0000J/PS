#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> graph[100001];
int ans[100001];

void bfs() {
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int num = q.front();
		q.pop();

		for (int i = 0; i < graph[num].size(); i++) {
			if (ans[num] != graph[num][i]) {
				q.push(graph[num][i]);
				ans[graph[num][i]] = num;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a;
		int b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= N; i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}