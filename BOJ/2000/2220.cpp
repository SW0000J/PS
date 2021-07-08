#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void swap(vector<int>& v, int i, int j) {
	int buf = v[j];
	v[j] = v[i];
	v[i] = buf;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> v(n + 1);
	v[1] = 1;

	for (int i = 2; i <= n; i++) {
		v[i] = i;

		swap(v, i, i - 1);

		for (int j = i - 1; j >= 2; j /= 2) {
			swap(v, j, j / 2);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << v[i] << " ";
	}
	cout << "\n";

	return 0;
}