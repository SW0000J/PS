#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> graph[101];
bool visited[101];
int ans = -1;

void dfs(int a, int b, int count) {
	visited[a] = true;

	if (a == b) {
		ans = count;
		return;
	}

	for (int i = 0; i < graph[a].size(); i++) {
		int next = graph[a][i];
		if (!visited[next]) {
			dfs(next, b, count + 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int n; std::cin >> n;
	std::pair<int, int> calc;
	std::cin >> calc.first >> calc.second;
	int m; std::cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		int y;
		std::cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	dfs(calc.first, calc.second, 0);
	std::cout << ans << "\n";

	return 0;
}