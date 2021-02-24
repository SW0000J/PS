#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N = 0;

	do {
		std::cin >> N;

		double top = 0;
		std::vector<std::string> v;

		for (int i = 0; i < N; i++) {
			std::string str;
			double h;
			std::cin >> str >> h;

			if (top < h) {
				top = h;

				v.clear();
				v.push_back(str);
			}
			else if (top == h) {
				v.push_back(str);
			}
		}

		for (int i = 0; i < v.size(); i++) {
			std::cout << v[i] << " ";
		}
		std::cout << "\n";
		
	} while (N != 0);

	return 0;
}