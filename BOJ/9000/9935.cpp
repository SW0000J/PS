#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string str;
	string boom;
	cin >> str >> boom;

	string ans;

	for (int i = 0; i < str.size(); i++) {
		ans += str[i];

		if (str[i] == boom[boom.length() - 1] && i >= boom.length() - 1) {
			bool flag = true;

			for (int j = 0; j < boom.length(); j++) {
				if (ans[ans.length() - boom.length() + j] != boom[j]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				for (int j = 0; j < boom.length(); j++) {
					ans.pop_back();
				}
			}
		}
	}

	if (ans.empty()) {
		cout << "FRULA\n";
	}
	else {
		cout << ans << "\n";
	}

	return 0;
}