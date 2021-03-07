#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string str; cin >> str;
	stack<char> st;

	for (int i = 0; i < str.length(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			cout << str[i];
		}
		else {
			if (str[i] == '(') {
				st.push(str[i]);
			}

			else if (str[i] == '*' || str[i] == '/') {
				while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
					cout << st.top();
					st.pop();
				}

				st.push(str[i]);
			}

			else if (str[i] == '+' || str[i] == '-') {
				while (!st.empty() && st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}

				st.push(str[i]);
			}

			else if (str[i] == ')') {
				while (!st.empty() && st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}

				st.pop();
			}
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}

	return 0;
}