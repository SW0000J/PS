#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	long long S; cin >> S;

	long long i = 1;
	long long ans = 0;
	long long total = 0;

	while (true) {
		total += i;

		if (total > S) {
			break;
		}

		ans++;
		i++;
	}

	cout << ans << "\n";

	return 0;
}