#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int K;
	int N;
	string str;
	cin >> N >> K;
	cin >> str;

	vector<char> v;

	for (int i = 0; i < str.length(); i++) {
		while (K > 0 && !v.empty() && v.back() < str[i]) {
			v.pop_back();
			K--;
		}

		v.push_back(str[i]);
	}

	for (int i = 0; i < v.size() - K; i++) {
		cout << v[i];
	}
	cout << "\n";

	return 0;
}