#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	std::string str; std::cin >> str;
	std::stack<char> st;
	int ans = 0;
	int point = 1;
	bool wrongFlag = false;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			point *= 2;
			st.push('(');
		}

		else if (str[i] == '[') {
			point *= 3;
			st.push('[');
		}

		else if (str[i] == ')') {
			if (st.empty() || st.top() != '(') {
				wrongFlag = true;
				break;
			}
			else if (str[i - 1] == '(')
				ans += point;
			st.pop();
			point /= 2;
		}

		else if (str[i] == ']') {
			if (st.empty() || st.top() != '[') {
				wrongFlag = true;
				break;
			}
			else if (str[i - 1] == '[')
				ans += point;
			st.pop();
			point /= 3;
		}
	}

	if (!st.empty() || wrongFlag)
		std::cout << 0 << "\n";
	else
		std::cout << ans << "\n";

	return 0;
}