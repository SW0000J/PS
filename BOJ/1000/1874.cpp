#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int input = 0;
	int num = 0;

	vector<int> v;
	stack<int> st;
	vector<char> v2;

	cin >> input;

	v.reserve(input);

	for (int i = 0; i < input; ++i) {
		int input = 0;
		cin >> input;
		v.push_back(input);
	}

	for (int i = 1; i <= input; ++i) {
		st.push(i);
		v2.push_back('+');

		while (!st.empty()) {
			if (st.top() == v.at(num)) {
				st.pop();
				v2.push_back('-');
				num++;
			}
			else
				break;
		}
	}

	if (st.empty()) {
		for (int i = 0; i < v2.size(); i++) {
			cout << v2.at(i) << "\n";
		}
	}
	else 
		cout << "NO";

	return 0;
}