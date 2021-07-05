#include <iostream>
#include <algorithm>
using namespace std;

bool arr[2001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		arr[num + 1000] = true;
	}

	for (int i = 0; i < 2001; i++) {
		if (arr[i]) {
			cout << i - 1000 << " ";
		}
	}
	cout << "\n";

	return 0;
}