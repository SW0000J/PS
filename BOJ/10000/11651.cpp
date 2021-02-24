#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<std::pair<int, int>> v(N);

	for (int i = 0; i < N; i++) {
		std::cin >> v[i].second >> v[i].first;
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		std::cout << v[i].second << " " << v[i].first << "\n";
	}

	return 0;
}