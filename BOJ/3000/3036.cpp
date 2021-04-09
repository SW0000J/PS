#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
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

	for (int i = 1; i < N; i++) {
		int div;

		if (v[0] > v[i]) {
			div = gcd(v[0], v[i]);
		}
		else {
			div = gcd(v[i], v[0]);
		}

		cout << v[0] / div << "/" << v[i] / div << "\n";
	}

	return 0;
}