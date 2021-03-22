#include <iostream>
#include <stack>
#include <string>
#include <iomanip>
using namespace std;

double arr[27];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;
	string str; cin >> str;
	stack<double> st;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '+') {
			double f = st.top();
			st.pop();
			double s = st.top();
			st.pop();

			st.push(s + f);
		}
		else if (str[i] == '-') {
			double f = st.top();
			st.pop();
			double s = st.top();
			st.pop();

			st.push(s - f);
		}
		else if (str[i] == '*') {
			double f = st.top();
			st.pop();
			double s = st.top();
			st.pop();

			st.push(s * f);
		}
		else if (str[i] == '/') {
			double f = st.top();
			st.pop();
			double s = st.top();
			st.pop();

			st.push(s / f);
		}
		else {
			st.push(arr[str[i] - 'A']);
		}
	}

	cout << fixed;
	cout.precision(2);

	cout << st.top() << "\n";

	return 0;
}