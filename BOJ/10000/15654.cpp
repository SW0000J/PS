#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int arr[9];
bool visited[9];
int N;
int M;

void dfs(const int& count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;

			arr[count] = v[i];
			dfs(count + 1);

			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;
	v.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	dfs(0);

	return 0;
}