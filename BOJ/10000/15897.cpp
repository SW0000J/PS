#include <iostream>
using namespace std;

// Harmonic Lemma

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	long long n; cin >> n;
	long long ans = 0;
	long long div = 0;
	long long quo = 0;

	for (long long i = 1; i < n; i = div + 1) {
		div = (n - 1) / ((n - 1) / i);
		quo = (n - 1) / i;

		ans += quo * (div - i + 1);
	}

	cout << ans + n << "\n";

	return 0;
}