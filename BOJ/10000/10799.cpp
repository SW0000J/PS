#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::string pipe; std::cin >> pipe;
	std::stack<char> st;

	int count = 0;

	for (int i = 0; i < pipe.length(); i++) {
		if(pipe[i] =='(')
			st.push(pipe[i]);
		else {
			st.pop();

			if (pipe[i - 1] == '(')
				count += st.size();
			else
				count++;
		}
	}

	std::cout << count << "\n";

	return 0;
}