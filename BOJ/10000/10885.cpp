#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		int N; cin >> N;
		vector<int> v(N);

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		int maxVal = INT_MIN;

		int twoCount = 0;
		bool positiveFlag = true;

		for (int i = 0; i < N; i++) {
			if (v[i] == 0) {
				twoCount = 0;
				positiveFlag = true;
			}
			else {
				if (v[i] == 2 || v[i] == -2) {
					twoCount++;
					//cout << i << " " << twoCount << " Two\n";
				}
				
				if (v[i] < 0) {
					positiveFlag = !positiveFlag;
					//cout << i << " " << positiveFlag << " POS\n";
				}

				if (positiveFlag) {
					maxVal = max(maxVal, twoCount);
				}
			}
		}

		twoCount = 0;
		positiveFlag = true;

		for (int i = N - 1; i >= 0; i--) {
			if (v[i] == 0) {
				twoCount = 0;
				positiveFlag = true;
			}
			else {
				if (v[i] == 2 || v[i] == -2) {
					twoCount++;
				}

				if (v[i] < 0) {
					positiveFlag = !positiveFlag;
				}

				if (positiveFlag) {
					maxVal = max(maxVal, twoCount);
				}
			}
		}

		int ans = INT_MIN;

		if (maxVal == INT_MIN) {
			for (int i = 0; i < N; i++) { 
				ans = max(ans, v[i]); 
			}
		}
		else {
			ans = 1;

			for (int i = 0; i < maxVal; i++) {
				ans = (2 * ans) % mod;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}