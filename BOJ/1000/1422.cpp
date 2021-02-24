#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

bool comp(const std::string& s1, const std::string& s2) {
	if (s1.length() == s2.length()) {
		return s1 > s2;
	}
	else {
		return s1.length() > s2.length();
	}
}

bool comp2(std::string s1, std::string s2) {
	return s1 + s2 > s2 + s1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int K;
	int N;
	std::cin >> K >> N;
	std::vector<std::string> v(K);
	std::vector<std::string> ans(N);
	int anssize = 0;

	for (int i = 0; i < K; i++) {
		std::cin >> v[i];
		ans[i] = v[i];
		anssize++;
	}

	std::sort(v.begin(), v.end(), comp);

	for (int i = anssize; i < N; i++) {
		ans[i] = v[0];
	}

	std::sort(ans.begin(), ans.end(), comp2);

	for (int i = 0; i < N; i++) {
		std::cout << ans[i];
	}
	std::cout << "\n";

	return 0;
}