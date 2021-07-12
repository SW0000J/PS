#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define mod 1000000007LL;

typedef vector<vector<long long>> matrix;
long long n;

matrix operator*(matrix& mat1, matrix& mat2) {
	matrix ans(2, vector<long long>(2));

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans[i][j] += mat1[i][k] * mat2[k][j];
			}

			ans[i][j] = ans[i][j] % mod;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;

	matrix ans = { {1, 0}
				  , {0, 1} };
	matrix mult = { {1, 1}
				  , {1, 0} };

	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * mult; // if odd -> mult matrix.
		}
		mult = mult * mult;
		n = n / 2;
	}

	cout << ans[1][0] << "\n";

	return 0;
}