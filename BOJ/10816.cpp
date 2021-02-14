#include <iostream>
#include <vector>
#include <algorithm>

// <Something new>
// upper_bound: Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
// lower_bound: Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.

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
	std::vector<int> ans(M);

	for (int i = 0; i < M; i++) {
		int num; std::cin >> num;

		ans[i] = std::upper_bound(v.begin(), v.end(), num) - std::lower_bound(v.begin(), v.end(), num);
	}

	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << " ";
	}
	std::cout << "\n";

	return 0;
}