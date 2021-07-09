#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string ans[101][101];

string intToStr(string a, string b) {
	string str;
	int buf = 0;

	while (!a.empty() || !b.empty() || buf != 0) {
		if (!a.empty()) {
			buf += a.back() - '0';
			a.pop_back();
		}

		if (!b.empty()) {
			buf += b.back() - '0';
			b.pop_back();
		}

		str.push_back((buf % 10) + '0');
		buf /= 10;
	}

	reverse(str.begin(), str.end());
	return str;
}

string comb(int a, int b) {
	if (a == b || b == 0) {
		return "1";
	}

	if (ans[a][b] != "") {
		return ans[a][b];
	}

	ans[a][b] = intToStr(comb(a - 1, b - 1), comb(a - 1, b));

	return ans[a][b];
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	int m;
	cin >> n >> m;

	cout << comb(n, m) << "\n";

	return 0;
}