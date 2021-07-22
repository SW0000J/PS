#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int gcd(int x, int y) {
	while (y != 0) {
		int buf = x % y;
		x = y;
		y = buf;
	}

	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int diff = v[1] - v[0];

	for (int i = 2; i < N; i++) {
		diff = gcd(diff, v[i] - v[i - 1]);
	}

	set<int> ans;
	ans.insert(diff);

	for (int i = 2; i * i <= diff; i++) {
		if (diff % i == 0) {
			ans.insert(i);
			ans.insert(diff / i);
		}
	}

	for (auto iter = ans.begin(); iter != ans.end(); iter++) {
		cout << *iter << " ";
	}
	cout << "\n";

	return 0;
}