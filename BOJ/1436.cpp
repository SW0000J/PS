#include <iostream>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	int order = 0;
	int ans = 0;

	while (order < N) {
		ans++;

		std::string str = std::to_string(ans);

		if (str.find("666") != -1) {
			order++;
		}
	}

	std::cout << ans << "\n";

	return 0;
}