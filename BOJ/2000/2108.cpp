#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::vector<int> v(N);
	std::vector<int> vcount(8001, 0);

	int sum = 0;
	int modecount = 0;
	for (int i = 0; i < N; i++) {
		std::cin >> v[i];
		sum += v[i];
		vcount[v[i] + 4000]++;
		if (vcount[v[i] + 4000] > modecount) {
			modecount = vcount[v[i] + 4000];
		}
	}

	// arithmetic mean
	std::cout << round(sum / (double)N) << "\n";

	std::sort(v.begin(), v.end());
	
	// median
	if (N % 2 == 0) {
		std::cout << (v[N / 2 - 1] + v[N / 2]) / 2 << "\n";
	}
	else {
		std::cout << v[N / 2] << "\n";
	}

	bool second = false;
	int mode = 0;
	for (int i = -4000; i <= 4000; i++) {
		if (vcount[i + 4000] == modecount) {
			mode = i;
			if (second) {
				break;
			}
			second = true;
		}
	}
	// mode 
	std::cout << mode << "\n";

	// range: <<max - min>>
	std::cout << v[v.size() - 1] - v[0] << "\n";

	return 0;
}