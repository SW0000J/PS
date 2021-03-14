#include <iostream>
#include <string>
using namespace std;

bool isSame(const string& str, const int& index) {
	int mid = (str.length() - index) / 2;

	for (int i = 0; i < mid; i++) {
		if (str[index + i] != str[str.length() - i - 1]) {
			return false;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string str; cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (isSame(str, i)) {
			cout << str.length() + i << "\n";
			break;
		}
	}

	return 0;
}