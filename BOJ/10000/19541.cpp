#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> meet[100001];
int infect[100001];
int original[100001];
int final[100001];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	int M;
	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		int k; cin >> k;

		for (int j = 1; j <= k; j++) {
			int a; cin >> a;

			meet[i].push_back(a);
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> infect[i];

		original[i] = infect[i];
		final[i] = infect[i];
	}

	for (int i = M; i > 0; i--) {
		bool unInfected = false;

		for (auto number : meet[i]) {
			if (infect[number] == 0) {
				unInfected = true;
				break;
			}
		}

		if (unInfected) {
			for (auto number : meet[i]) {
				infect[number] = 0;
				original[number] = 0;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		infect[i] = original[i];
	}

	for (int i = 1; i <= M; i++) {
		bool infected = false;

		for (auto number : meet[i]) {
			if (infect[number] == 1) {
				infected = true;
				break;
			}
		}

		if (infected) {
			for (auto number : meet[i]) {
				infect[number] = 1;
			}
		}
	}

	bool canTrack = true;

	for (int i = 1; i <= N; i++) {
		if (infect[i] != final[i]) {
			canTrack = false;
			break;
		}
	}

	if (canTrack) {
		cout << "YES\n";

		for (int i = 1; i <= N; i++) {
			cout << original[i] << " ";
		}
	}
	else {
		cout << "NO\n";
	}

	return 0;
}