#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	vector<long long> v;

	for (int i = 0; i < N; i++) {
		long long num; cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	long long ans = v[0];
	int count = 0;
	int max = 0;

	for (int i = 1; i < N; i++) {
		if (v[i - 1] == v[i]) {
			count++;
		}
		else {
			count = 0;
		}

		if (max < count) {
			max = count;
			ans = v[i];
		}
	}

	cout << ans << "\n";

	return 0;
}