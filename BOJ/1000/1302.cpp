#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	map<string, int> m;
	
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		m[str]++;
	}

	int num = 0;
	string ans;

	for (auto item : m) {
		num = max(num, item.second);
	}

	for (auto item : m) {
		if (num == item.second) {
			ans = item.first;
			break;
		}
	}

	cout << ans << "\n";

	return 0;
}