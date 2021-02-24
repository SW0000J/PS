#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<int> v(N);

	for (int i = 0; i < N; i++) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	int M; std::cin >> M;

	for (int i = 0; i < M; i++) {
		int num; std::cin >> num;

		if (std::binary_search(v.begin(), v.end(), num)) {
			std::cout << 1 << " ";
		}
		else {
			std::cout << 0 << " ";
		}
	}
	std::cout << "\n";
	return 0;
}