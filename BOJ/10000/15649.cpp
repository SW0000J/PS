#include <iostream>
using namespace std;

int arr[9];
bool visited[9];

void dfs(const int& n, const int& m, const int& count) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;

			arr[count] = i;
			dfs(n, m, count + 1);

			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	dfs(N, M, 0);

	return 0;
}