#include <iostream>
#include <cmath>
using namespace std;

int main() {

	while (true) {
		int n; cin >> n;
		int ans = 0;

		if (n == 0) {
			break;
		}

		for (int i = n + 1; i <= n * 2; i++) {
			int num = sqrt(i);

			if (num == 1) {
				ans++;
				continue;
			}

			if (i % 2 == 1) {
				for (int j = 2; j <= num; j++) {
					if (i % j == 0) {
						break;
					}
					else if(j == num) {
						ans++;
					}
				}
			}
		}

		cout << ans << "\n";
	}

	return 0;
}