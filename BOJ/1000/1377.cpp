#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i].first;
		v[i].second = i;	// first position
	}

	sort(v.begin(), v.end());

	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans = max(ans, v[i].second - i + 1);
	}

	cout << ans << "\n";

	return 0;
}