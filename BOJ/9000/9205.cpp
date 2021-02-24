#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

int visited[102] = { 0, };
std::vector<int> g[102];

void dfs(int start) {
	visited[start] = true;

	for (int i = 0; i < g[start].size(); i++) {
		int next = g[start][i];

		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int t; std::cin >> t;

	for (int tc = 0; tc < t; tc++) {
		for (int i = 0; i < 102; i++) {
			g[i].clear();
		}

		memset(visited, 0, sizeof(visited));

		int n; std::cin >> n;
		std::vector<std::pair<int, int>> v(n + 2);

		for (int i = 0; i < n + 2; i++) {
			std::cin >> v[i].first >> v[i].second;
		}
		
		for (int i = 0; i < n + 2; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				if (abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second) <= 1000) {
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}

		dfs(0);

		if (visited[n + 1]) {
			std::cout << "happy\n";
		}
		else {
			std::cout << "sad\n";
		}
	}

	return 0;
}