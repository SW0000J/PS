#include <iostream>
using namespace std;

int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		int A;
		int B;
		cin >> A >> B;

		cout << lcm(A, B) << "\n";
	}

	return 0;
}