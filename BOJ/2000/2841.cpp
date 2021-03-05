#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int P;
	cin >> N >> P;

	stack<int> st[7];
	int ans = 0;

	for (int i = 0; i < N; i++) {
		int n;
		int p;
		cin >> n >> p;

		while (!st[n].empty() && st[n].top() > p) {
			st[n].pop();
			ans++;
		}

		if (st[n].empty() || st[n].top() < p) {
			st[n].push(p);
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}