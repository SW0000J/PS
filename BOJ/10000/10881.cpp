#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int wid[6];
int hei[6];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int tc = 0; tc < T; tc++) {
		for (int i = 0; i < 3; i++) {
			cin >> wid[i] >> hei[i];

			wid[i + 3] = hei[i];
			hei[i + 3] = wid[i];
		}

		int minVal = INT_MAX;

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					if (i % 3 == j % 3 || j % 3 == k % 3 || k % 3 == i % 3) {
						continue;
					}

					minVal = min(minVal, min((wid[i] + wid[j] + wid[k]) * max(hei[i], max(hei[j], hei[k])), max(wid[i] + wid[j], wid[k]) * (max(hei[i], hei[j]) + hei[k])));
				}
			}
		}

		cout << minVal << "\n";
	}

	return 0;
}