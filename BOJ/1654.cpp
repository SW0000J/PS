#include <iostream>
#include <algorithm>
#include <vector>

// binary search: start, end -> loop

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	long long K; 
	long long N;
	std::cin >> K >> N;
	std::vector<long long> v(K);

	for (int i = 0; i < K; i++) {
		std::cin >> v[i];
	}

	std::sort(v.begin(), v.end());

	long long start = 1;
	long long end = v[K - 1];
	long long max = 0;

	while (start <= end) {
		long long mid = (start + end) / 2;
		long long count = 0;

		for (int i = 0; i < v.size(); i++) {
			count += v[i] / mid;
		}

		if (count >= N) {
			start = mid + 1;

			max = std::max(max, mid);
		}
		else {
			end = mid - 1;
		}
	}

	std::cout << max << "\n";

	return 0;
}