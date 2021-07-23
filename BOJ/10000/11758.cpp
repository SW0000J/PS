#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	pair<int, int> p1;
	pair<int, int> p2;
	pair<int, int> p3;

	cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;

	int s = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

	if (s > 0) {
		cout << "1\n";
	}
	else if (s < 0) {
		cout << "-1\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}