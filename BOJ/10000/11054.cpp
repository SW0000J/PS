#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	vector<int> v(N + 1);
	vector<int> dpF(N + 1, 1);
	vector<int> dpR(N + 1, 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			if (v[i] > v[j] && dpF[i] < dpF[j] + 1) {
				dpF[i] = dpF[j] + 1;
			}
		}

	}

	for (int i = N; i >= 1; i--) {
		for (int j = N; j >= i; j--) {
			if (v[i] > v[j] && dpR[i] < dpR[j] + 1) {
				dpR[i] = dpR[j] + 1;
			}
		}

	}

	int ans = 0;

	for (int i = 0; i <= N; i++) {
		ans = max(ans, dpF[i] + dpR[i] - 1);
	}

	std::cout << ans << "\n";

	return 0;
}