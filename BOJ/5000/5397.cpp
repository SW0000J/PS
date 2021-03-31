#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		string str; cin >> str;
		list<char> lst;
		list<char>::iterator iter = lst.begin();

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '<' && iter != lst.begin()) {
				iter--;
			}
			else if (str[j] == '>' && iter != lst.end()) {
				iter++;
			}
			else if (str[j] == '-' && iter != lst.begin()) {
				iter = lst.erase(--iter);
			}
			else if (str[j] != '<' && str[j] != '>' && str[j] != '-') {
				lst.insert(iter, str[j]);
			}
		}

		for (auto item : lst) {
			cout << item;
		}
		cout << "\n";
	}

	return 0;
}