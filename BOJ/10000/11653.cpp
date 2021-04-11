#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	while (true) {
		if (N == 1) {
			break;
		}

		for (int i = 2; i <= N; i++) {
			if (N % i == 0) {
				cout << i << "\n";
				N /= i;
				break;
			}
		}
	}

	return 0;
}