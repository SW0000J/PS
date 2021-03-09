#include <iostream>
#include <string>
using namespace std;

int arr[64][64];

void QT(int x, int y, int size) {
	if (size == 1) {
		cout << arr[x][y];
		return;
	}

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (arr[x][y] != arr[i][j]) {
				cout << '(';
				// Compression order should be considered
				QT(x, y, size / 2);
				QT(x, y + size / 2, size / 2);
				QT(x + size / 2, y, size / 2);
				QT(x + size / 2, y + size / 2, size / 2);
				cout << ')';
				return;
			}
		}
	}

	cout << arr[x][y];
	return;
}

int main() {
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		string str; cin >> str;

		for (int j = 0; j < str.length(); j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	QT(0, 0, N);

	return 0;
}