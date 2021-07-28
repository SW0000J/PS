#include <iostream>
#include <algorithm>
#include <vector>
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

	long long ans = 0;

	//time over error
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			ans += nameV[i] ^ nameV[j];
		}
	}

	cout << ans << "\n";

	return 0;
}