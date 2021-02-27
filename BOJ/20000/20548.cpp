#include <iostream>
#include <cmath>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	long long c; std::cin >> c;
	long long ans = 0;
	int squ = 1;

	while (true) {
		if (c <= 0) {
			break;
		}

		ans += (c % 7) * squ;
		c /= 7;
		squ *= 3;
	}

	std::cout << ans << "\n";

	return 0;
}