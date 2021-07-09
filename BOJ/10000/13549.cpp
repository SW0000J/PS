#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int K;
bool visit[100001];

int bfs() {
	visit[N] = true;

	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, N));

	while (!pq.empty()) {
		int time = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (K == x) {
			return time;
		}

		if (2 * x < 100001 && !visit[2 * x]) {
			pq.push(make_pair(time, 2 * x));
			visit[2 * x] = true;
		}

		if (x - 1 >= 0 && !visit[x - 1]) {
			pq.push(make_pair(time + 1, x - 1));
			visit[x - 1] = true;
		}

		if (x + 1 < 100001 && !visit[x + 1]) {
			pq.push(make_pair(time + 1, x + 1));
			visit[x + 1] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;

	cout << bfs() << "\n";

	return 0;
}