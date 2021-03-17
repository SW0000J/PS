#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double X;
	double Y;
	cin >> X >> Y;

	double Z = floor(100 * Y / X);
	long long ans = 1;

	//cout << Z << "\n";

	if (Z >= (double)99) {
		cout << "-1\n";
	}
	else {
		ans = (int)ceil((100 * Y - X * Z - X) / (Z - 99));
		cout << ans << "\n";
	}

	return 0;
}