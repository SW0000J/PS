#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int X; cin >> X;
	string str; cin >> str;

	int man = 0;
	int woman = 0;
	bool flag = false;
	char buf;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'M') {
			int diff = abs((man + 1) - woman);

			if (diff > X) {
				if (!flag) {
					buf = 'M';
					flag = true;
				}
				else {
					break;
				}
			}
			else {
				man++;
			}
		}
		else if (str[i] == 'W') {
			int diff = abs(man - (woman + 1));

			if (diff > X) {
				if (!flag) {
					buf = 'W';
					flag = true;
				}
				else {
					break;
				}
			}
			else {
				woman++;
			}
		}

		if (flag) {
			if (buf == 'M') {
				int diff = abs((man + 1) - woman);

				if (diff <= X) {
					man++;
					flag = false;
				}
			}
			else if (buf == 'W') {
				int diff = abs(man - (woman + 1));

				if (diff <= X) {
					woman++;
					flag = false;
				}
			}
		}
	}

	cout << man + woman << "\n";

	return 0;
}