#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		map<string, int> m;
		int n; cin >> n;

		for (int i = 0; i < n; i++) {
			string kind;
			string name;

			cin >> name >> kind;

			if (m.find(kind) == m.end()) {
				m.insert(make_pair(kind, 1));
			}
			else {
				m[kind]++;
			}
		}

		int ans = 1;

		for (auto item : m) {
			ans *= (item.second + 1);
		}
		
		cout << ans - 1 << "\n";
	}

	return 0;
}