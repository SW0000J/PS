#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	stack<int> st;

	for (int i = 0; i < N; i++) {
		int h; cin >> h;
		st.push(h);
	}

	int max = 0;
	int ans = 0;

	while (!st.empty()) {
		if (max < st.top()) {
			max = st.top();
			ans++;
		}

		st.pop();
	}

	cout << ans << "\n";

	return 0;
}