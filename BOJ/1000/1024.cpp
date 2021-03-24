#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int L;
	cin >> N >> L;

	bool flag = true;

	for (int i = L; i <= 100; i++) {
		int num = N - i * (i - 1) / 2;

		if (num % i == 0 && num / i >= 0) {
			int ans = num / i;

			for (int j = 0; j < i; j++) {
				cout << j + ans << " ";
			}
			cout << "\n";

			flag = false;
			break;
		}
	}

	if (flag) {
		cout << "-1\n";
	}

	return 0;
}