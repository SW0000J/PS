#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int K;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;

	vector<int> height(N);
	for (int i = 0; i < N; i++) {
		cin >> height[i];
	}

	vector<int> diff(N - 1);
	for (int i = 0; i < N - 1; i++) {
		diff[i] = height[i + 1] - height[i];
	}

	sort(diff.begin(), diff.end());

	int ans = 0;
	for (int i = 0; i < (N - 1) - (K - 1); i++) {
		ans += diff[i];
	}

	cout << ans << "\n";

	return 0;
}