#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<int> A(N);
	std::vector<int> B(N);

	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	std::sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}

	std::sort(B.begin(), B.end(), std::greater<>());
	int sum = 0;

	for (int i = 0; i < N; i++) {
		sum += A[i] * B[i];
	}

	std::cout << sum << "\n";

	return 0;
}