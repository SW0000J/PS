#include <iostream>
using namespace std;

int arr[9];
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
		arr[count] = i;
		dfs(i, count + 1);

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