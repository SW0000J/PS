#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M;
int K;
int arr[301][301];
int sum[301][301];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
		}
	}

	cin >> K;

	for (int loop = 0; loop < K; loop++) {
		int i;
		int j;
		int x;
		int y;
		cin >> i >> j >> x >> y;
		
		int ans = sum[x][y] - sum[x][j - 1] - sum[i - 1][y] + sum[i - 1][j - 1];

		cout << ans << "\n";
	}

	return 0;
}