#include <iostream>
#include <algorithm>
using namespace std;

int k;
int ans[6];
int s[13];

void dfs(int n, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = n; i < k; i++) {
			ans[depth] = s[i];
			dfs(i + 1, depth + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	while (true) {
		cin >> k;

		if (k == 0) {
			break;
		}

		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}

		dfs(0, 0);
		cout << "\n";
	}

	return 0;
}