#include <iostream>
using namespace std;

int N;
int ans = 0;
int board[15];

bool promising(int i) {
	for (int j = 0; j < i; j++) {
		if (board[i] == board[j] || (i - j) == abs(board[i] - board[j])) {
			return false;
		}
	}
	
	return true;
}

void dfs(int i) {
	if (i == N) {
		ans += 1;
	}
	else {
		for (int j = 0; j < N; j++) {
			board[i] = j;

			if (promising(i)) {
				dfs(i + 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	dfs(0);

	cout << ans << "\n";

	return 0;
}