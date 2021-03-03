#include <iostream>
using namespace std;

int arr[9];
bool visited[9];
int N;
int M;

void dfs(const int& start, const int& count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = start; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;

			arr[count] = i;
			dfs(i + 1, count + 1);

			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	dfs(1, 0);

	return 0;
}