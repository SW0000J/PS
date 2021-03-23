#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M;
	int N;
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		int root = sqrt(i);

		if (i != 1 && root == 1) {
			cout << i << "\n";
		}
		else if (i % 2 == 1) {
			for (int j = 2; j <= root; j++) {
				if (i % j == 0) {
					break;
				}

				if (j == root) {
					cout << i << "\n";
				}
			}
		}
	}


	return 0;
}