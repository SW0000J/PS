#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::string s; std::cin >> s;
	std::vector<char> v;

	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i]);
	}

	std::sort(v.begin(), v.end(), std::greater<>());

	for (int i = 0; i < s.length(); i++) {
		std::cout << v[i];
	}
	std::cout << "\n";

	return 0;
}