#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int k; cin >> k;
		multiset<int> ms;

		for (int i = 0; i < k; i++) {
			char c;
			int n;
			cin >> c >> n;

			if (c == 'I') {
				ms.insert(n);
			}
			else {
				if (!ms.empty()) {
					if (n == 1) {
						auto iter = ms.end();
						iter--;
						ms.erase(iter);
					}
					else {
						ms.erase(ms.begin());
					}
				}
			}
		}

		if (ms.empty()) {
			cout << "EMPTY\n";
		}
		else {
			auto end = ms.end();
			end--;
			cout << *end << " " << *ms.begin() << "\n";
		}
	}

	return 0;
}