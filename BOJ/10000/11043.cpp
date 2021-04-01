#include <iostream>
#include <cstring>
using namespace std;

int arr[100][100];
bool visited[100];

void dfs(const int& N, int index) {
	for (int i = 0; i < N; i++) {
		if (!visited[i] && arr[index][i]) {
			visited[i] = true;
			dfs(N, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		dfs(N, i);

		for (int j = 0; j < N; j++) {
			if (visited[j]) {
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}