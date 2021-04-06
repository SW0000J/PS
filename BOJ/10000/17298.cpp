#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	vector<int> v(N);
	stack<int> st;

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	vector<int> ans(N, -1);

	for (int i = 0; i < N; i++) {
		while (!st.empty() && v[st.top()] < v[i]) {
			ans[st.top()] = v[i];
			st.pop();
		}

		st.push(i);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";

	return 0;
}