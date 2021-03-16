#include <iostream>
using namespace std;

bool arr[1001];
int N;
int K;
int ans = 0;

void Era() {
	for (int i = 2; i <= N; i++) {
		if (!arr[i]) {
			for (int j = 1; i * j <= N; j++) {
				if (!arr[i * j]) {
					arr[i * j] = true;
					ans++;
				}

				if (ans == K) {
					cout << i * j << "\n";
					return;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;

	Era();

	return 0;
}