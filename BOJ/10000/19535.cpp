#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
long long D = 0;
long long G = 0;
vector<int> tree[300001];
int count[300001];

long long calcNode(int n) {
	return max(n * 1LL * (n - 1) * (n - 2) / 6LL, 1LL);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int u;
		int v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	for (int i = 1; i <= N; i++) {
		if (tree[i].size() >= 3) {
			G += calcNode(tree[i].size());
		}

		if (tree[i].size() >= 2) {
			for (auto nextNode : tree[i]) {
				if (tree[nextNode].size() >= 2) {
					D += (tree[nextNode].size() - 1) * 1LL * (tree[i].size() - 1);
				}
			}
		}
	}

	if (D / 2 == G * 3) {
		cout << "DUDUDUNGA\n";
	}
	else if (D / 2 > G * 3) {
		cout << "D\n";
	}
	else {
		cout << "G\n";
	}

	return 0;
}