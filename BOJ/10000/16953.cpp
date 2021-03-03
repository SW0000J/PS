#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long A;
long long B;
int ans = INT_MAX;

void bfs(const long long& a, int count) {
	if (a > B) {
		// cout << a << "\n";
		return;
	}
	else if (a == B) {
		ans = min(ans, count);
		// cout << ans << "\n";
	}
	
	bfs(a * 2, count + 1);
	bfs(a * 10 + 1, count + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> A >> B;

	bfs(A, 1);

	if (ans == INT_MAX) {
		cout << -1 << "\n";
	}
	else {
		cout << ans << "\n";
	}

	return 0;
}