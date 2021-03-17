#include <iostream>
#include <vector>
using namespace std;

vector<int> v[50];

int N;
int delnode;

int dfs(int root) {
	int ans = 0;
	
	for (int i = 0; i < v[root].size(); i++) {
		if (v[root][i] == delnode) {
			continue;
		}
		else {
			ans += dfs(v[root][i]);
		}
	}

	if (ans == 0) {
		return 1;
	}
	else {
		return ans;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	int root = -1;

	for (int i = 0; i < N; i++) {
		int node; cin >> node;
		if (node == -1) {
			root = i;
		}
		else {
			v[node].push_back(i);
		}
	}

	cin >> delnode;

	if (root == delnode) {
		cout << "0\n";
	}
	else {
		cout << dfs(root) << "\n";
	}

	return 0;
}