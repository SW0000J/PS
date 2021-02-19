#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<std::string>> v(201);

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	
	for (int i = 0; i < N; i++) {
		int num; std::cin >> num;
		std::string name; std::cin >> name;

		v[num].push_back(name);
	}

	for (int i = 1; i <= 200; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			std::cout << i << " " << v[i][j] << "\n";
		}
	}

	return 0;
}