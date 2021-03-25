#include <iostream>
using namespace std;

void draw(const int& N, int a, int b) {
	if (a % 3 == 1 && b % 3 == 1) {
		cout << " ";
		return;
	}
	else if (N == 1) {
		cout << "*";
		return;
	}
	else {
		draw(N / 3, a / 3, b / 3);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			draw(N, i, j);
		}
		cout << "\n";
	}

	return 0;
}