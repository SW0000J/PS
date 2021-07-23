#include <iostream>
#include <algorithm>
using namespace std;

int set[1000001];

int find(int num) {
	if (set[num] == num) {
		return num;
	}
	else {
		set[num] = find(set[num]);
	}

	return set[num];
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) {
		set[a] = b;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n;
	int m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		set[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int num;
		int a;
		int b;
		cin >> num >> a >> b;

		if (num == 1) {
			if (find(a) == find(b)) {
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}

		if (num == 0) {
			merge(a, b);
		}
	}

	return 0;
}