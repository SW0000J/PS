#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int N; cin >> N;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int tc = 0; tc < N; tc++) {
		int num; cin >> num;

		if (num == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top().second << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(abs(num), num));
		}
	}

	return 0;
}