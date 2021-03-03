#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int arr[9];
int ans[9];
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

	int used = 0;

	for (int i = start; i <= N; i++) {
		if (used != v[i]) {
			arr[count] = v[i];
			used = v[i];
			dfs(i, count + 1);
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

	dfs(1, 0);

	return 0;
}