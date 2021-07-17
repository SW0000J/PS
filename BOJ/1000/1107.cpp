#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> brokenFlag(10);

int buttonCount(int num) {
	int count = 0;

	if (num > 0) {
		while (num > 0) {
			if (brokenFlag[num % 10]) {
				return 0;
			}

			num /= 10;
			count++;
		}

		return count;
	}
	else {
		if (brokenFlag[0]) {
			return 0;
		}
		else {
			return 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	int M; cin >> M;

	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		brokenFlag[num] = true;
	}

	int minCount = max(100 - N, N - 100);

	if (N != 100) {
		for (int i = 0; i <= 1000007; i++) {
			int count = buttonCount(i);

			if (count != 0) {
				minCount = min(minCount, count + max(N - i, i - N));
			}
		}
	}

	cout << minCount << "\n";

	return 0;
}