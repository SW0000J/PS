#include <iostream>
#include <queue>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int N; std::cin >> N;
	std::queue<int> q;
	
	for (int i = 0; i < N; i++) {
		std::string str; std::cin >> str;

		if (str == "push") {
			int num; std::cin >> num;
			q.push(num);
		}

		else if (str == "front") {
			
			if (!q.empty())
				std::cout << q.front() << "\n";
			else
				std::cout << -1 << "\n";
		}

		else if (str == "back") {

			if (!q.empty())
				std::cout << q.back() << "\n";
			else
				std::cout << -1 << "\n";
		}

		else if (str == "pop") {
			if (!q.empty()) {
				std::cout << q.front() << "\n";
				q.pop();
			}
			else {
				std::cout << -1 << "\n";
			}
		}

		else if (str == "size") {
			std::cout << q.size() << "\n";
		}

		else if (str == "empty") {
			if (!q.empty())
				std::cout << 0 << "\n";
			else
				std::cout << 1 << "\n";
		}
	}

	return 0;
}