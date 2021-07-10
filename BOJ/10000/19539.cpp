#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	vector<int> v(N);

	int div = 0;
	int rem = 0;

	for (int i = 0; i < N; i++) {
		cin >> v[i];

		div += v[i] / 2;
		rem += v[i] % 2;
	}

	if (div >= rem && (div - rem) % 3 == 0) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

	return 0;
}