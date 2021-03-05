#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	int ans = 0;

	for (int l = 0; l < N; l++) {
		string s; cin >> s;
		stack<char> st;
		
		for (int i = 0; i < s.size(); i++) {
			if (!st.empty() && st.top() == s[i]) {
				st.pop();
			}
			else {
				st.push(s[i]);
			}
		}

		if (st.empty()) {
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}