#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N;
	int M;
	std::cin >> N >> M;
	std::vector<int> v(N);

	for (int i = 0; i < N; i++) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		int num; std::cin >> num;
		
		if (std::binary_search(v.begin(), v.end(), num)) {
			std::cout << std::lower_bound(v.begin(), v.end(), num) - v.begin() << "\n";
		}
		else {
			std::cout << -1 << "\n";
		}
	}

	return 0;
}