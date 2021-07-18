#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N;
int ans = 0;
int dx[6] = { 0, 1, 1, 0, -1, -1 };
int dy[6] = { 2, 1, -1, -2, -1, 1 };

map<pair<int, int>, int> visit;

void dfs(int x, int y, int dirNum, int moveCount) {
	if (moveCount == N) {
		if (visit.find(make_pair(x, y)) != visit.end()) {

			//for (auto i = visit.begin(); i != visit.end(); i++) {
			//	cout << "x: " << x << ", " << "y: " << y << "\n";
			//	cout << "key: <" << i->first.first << ", " << i->first.second << "> " << ", " << i->second << "\n";
			//}
			//cout << "\n";

			ans++;
		}

		return;
	}
	
	if (visit.find(make_pair(x, y)) != visit.end()) {
		return;
	}

	//cout << "x: " << x << ", " << "y: " << y << "\n";
	visit[make_pair(x, y)] = true;

	int rightDir = (dirNum + 1) % 6;
	int leftDir = (dirNum + 5) % 6;

	dfs(x + dx[rightDir], y + dy[rightDir], rightDir, moveCount + 1);
	dfs(x + dx[leftDir], y + dy[leftDir], leftDir, moveCount + 1);

	visit.erase(make_pair(x, y));
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	visit[make_pair(0, 0)] = 0;
	dfs(0, 2, 0, 0);

	cout << ans << "\n";

	return 0;
}