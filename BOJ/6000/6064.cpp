#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
	while (y != 0) {
		int rem = x % y;
		x = y;
		y = rem;
	}

	return x;
}

int lcm(int x, int y) {
	return (x * y) / gcd(x, y);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int M;
		int N;
		int x;
		int y;
		cin >> M >> N >> x >> y;

		while (x <= lcm(M, N) && x != y) {
			if (x < y) {
				x += M;
			}
			else {
				y += N;
			}
		}

		if (x != y) {
			cout << -1 << "\n";
		}
		else {
			cout << x << "\n";
		}
	}

	return 0;
}