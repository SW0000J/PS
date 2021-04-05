#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int order = 1;

	while (true) {
		string str; cin >> str;

		if (str[0] == '-') {
			break;
		}

		int ans = 0;
		stack<char> st;

		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '}' && !st.empty() && st.top() == '{') {
				st.pop();
			}
			else {
				st.push(str[i]);
			}
		}

		while (!st.empty()) {
			char c1 = st.top();
			st.pop();
			char c2 = st.top();
			st.pop();

			if (c1 == c2) {
				ans++;
			}
			else {
				ans += 2;
			}
		}

		cout << order++ << ". " << ans << "\n";
	}

	return 0;
}