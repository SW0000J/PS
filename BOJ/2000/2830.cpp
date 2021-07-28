#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	vector<long long> nameV(N);

	for (int i = 0; i < N; i++) {
		cin >> nameV[i];
	}

	vector<pair<long long, long long>> binaryV(20);
	long long ans = 0;

	for (long long i = 0; i < nameV.size(); i++) {
		for (long long j = 0; j < binaryV.size(); j++) {
			if (nameV[i] & (1 << j)) {
				binaryV[j].second++;
			}
			else {
				binaryV[j].first++;
			}
		}

		for (long long j = 0; j < binaryV.size(); j++) {
			if (nameV[i] & (1 << j)) {
				ans += binaryV[j].first * (1 << j);
			}
			else {
				ans += binaryV[j].second * (1 << j);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}