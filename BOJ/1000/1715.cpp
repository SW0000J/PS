#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int buf; cin >> buf;
		pq.push(buf);
	}

	int ans = 0;

	for (int i = 0; i < N - 1; i++) {
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		pq.push(first + second);
		ans += first + second;
	}

	cout << ans << "\n";

	return 0;
}