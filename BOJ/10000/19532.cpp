#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	cin >> a >> b >> c >> d >> e >> f;

	for (int x = -999; x <= 999; x++) {
		for (int y = -999; y <= 999; y++) {
			if ((a * x + b * y) == c && (d * x + e * y) == f) {
				cout << x << " " << y << "\n";
				break;
			}
		}
	}

	return 0;
}