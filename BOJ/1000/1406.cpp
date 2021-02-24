#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	// left stack, right stack
	std::stack<char> inp;
	std::stack<char> ans;
	std::string str; std::cin >> str;
	int N = str.length();

	for (int i = 0; i < N; i++) {
		inp.push(str[i]);
	}

	int M; std::cin >> M;

	for (int i = 0; i < M; i++) {
		char com; std::cin >> com;

		if (com == 'L') {
			if (!inp.empty()) {
				ans.push(inp.top());
				inp.pop();
			}
		}
		else if (com == 'D') {
			if (!ans.empty()) {
				inp.push(ans.top());
				ans.pop();
			}
		}
		else if (com == 'B') {
			if (!inp.empty()) {
				inp.pop();
			}
		}
		else if (com == 'P') {
			char c; std::cin >> c;
			inp.push(c);
		}
	}

	while (!inp.empty()) {
		ans.push(inp.top());
		inp.pop();
	}

	while (!ans.empty()) {
		std::cout << ans.top();
		ans.pop();
	}
	std::cout << "\n";

	return 0;
}