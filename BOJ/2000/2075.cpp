#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	
	int N; cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N; j++) {
			int num; cin >> num;
			pq.push(num);
		}

		for (int j = 0; j < N; j++) {
			pq.pop();
		}
	}

	cout << pq.top();

	return 0;
}