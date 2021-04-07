#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int k, int start, int mid, int end) {
	if (k == 1) {
		cout << start << " " << end << "\n";
	}
	else {
		hanoi(k - 1, start, end, mid);
		cout << start << " " << end << "\n";
		hanoi(k - 1, mid, start, end);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int k; cin >> k;
	
	cout << (int)pow(2, k) - 1 << "\n";

	hanoi(k, 1, 2, 3);
	
	return 0;
}