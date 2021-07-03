#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	priority_queue<int, vector<int>, less<int>> maxpq;
	priority_queue<int, vector<int>, greater<int>> minpq;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;

		if (maxpq.size() > minpq.size()) {
			minpq.push(n);
		}
		else {
			maxpq.push(n);
		}

		if (!maxpq.empty() && !minpq.empty() && maxpq.top() > minpq.top()) {
			int maxTop = maxpq.top();
			int minTop = minpq.top();

			maxpq.pop();
			minpq.pop();
			
			maxpq.push(minTop);
			minpq.push(maxTop);
		}

		cout << maxpq.top() << "\n";
	}

	return 0;
}