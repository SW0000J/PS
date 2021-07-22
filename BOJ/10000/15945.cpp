#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long maxNum = LLONG_MIN;
long long minNum = LLONG_MAX;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n; cin >> n;

	bool zeroFlag = true;

	for (int i = 0; i < n; i++) {
		long long num; cin >> num;

		if (num == 0) {
			continue;
		}

		zeroFlag = false;
		
		maxNum = max(maxNum, num);
		minNum = min(minNum, num);
	}

	long long ans = 0;

	if (!(zeroFlag || maxNum * minNum < 0 || maxNum == minNum)) {
		if (minNum < 0) {
			ans = min(abs(maxNum), maxNum - minNum);
		}
		else {
			ans = min(minNum, maxNum - minNum);
		}
	}

	cout << ans << "\n";

	return 0;
}