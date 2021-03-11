#include <iostream>
using namespace std;

bool isPrime(int n) {
	if (n <= 1) {
		return false;
	}

	for (int i = 2; i < n; i++) {
		if ((n % i) == 0) {
			return false;
		}
	}
	return true;
}

void goldPart(int num) {
	int num1;
	int num2;
	for (int i = num / 2; i >= 0; i--) {
		if (isPrime(i) && isPrime(num - i)) {
			num1 = i;
			num2 = num - i;
			break;
		}
	}

	cout << num1 << ' ' << num2 << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int T; cin >> T;
	int loop = 0;

	while (loop < T) {
		int n;
		cin >> n;
		goldPart(n);
		loop++;
	}

	return 0;
}