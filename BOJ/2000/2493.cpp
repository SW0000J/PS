#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	stack<pair<int, int>> st;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;

		while (!st.empty()) {
			if (st.top().second > n) {
				cout << st.top().first << " ";
				break;
			}

			st.pop();
		}

		if (st.empty()) {
			cout << 0 << " ";
		}
		st.push(make_pair(i + 1, n));
	}

	return 0;
}