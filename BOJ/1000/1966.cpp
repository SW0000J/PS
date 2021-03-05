#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int testcase;
	cin >> testcase;

	int answer = 0;
	int N;
	int M;
	int importNum;

	for (int t = 0; t < testcase; t++) {
		answer = 0;
		cin >> N >> M;

		priority_queue<int> pq;
		queue<pair<int, int>> q;

		for (int i = 0; i < N; i++) {
			cin >> importNum;
			q.push({ i, importNum });
			pq.push(importNum);
		}

		while (!q.empty()) {
			int index = q.front().first;
			int importNum = q.front().second;

			q.pop();


			if (pq.top() == importNum) {
				pq.pop();
				answer++;

				if (index == M) {
					cout << answer << "\n";
					break;
				}
			}
			else {
				q.push({ index, importNum });
			}
		}
	}

	return 0;
}