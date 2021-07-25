#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;

struct line {
	long long startX;
	long long startY;
	long long endX;
	long long endY;
	long long dir;
	long long length;
};

long long dx[4] = { 0, 1, 0, -1 };
long long dy[4] = { 1, 0, -1, 0 };

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	long long L; cin >> L;
	long long N; cin >> N;
	long long nowX = 0;
	long long nowY = 0;
	long long nowDir = 1;

	vector<line> v;
	bool finishFlag = false;

	long long ans = 0;

	for (int i = 0; i <= N; i++) {
		long long t;
		char dirChar;

		if (i != N) {
			cin >> t >> dirChar;
		}
		else if (i == N) {
			t = LLONG_MAX;
		}

		if (finishFlag) {
			continue;
		}

		long long minVal = LLONG_MAX;

		long long newX = nowX + t * dx[nowDir];
		long long newY = nowY + t * dy[nowDir];

		if (newX > L) {
			minVal = min(minVal, L - nowX + 1);
		}
		else if (newX < -L) {
			minVal = min(minVal, L + nowX + 1);
		}
		else if (newY > L) {
			minVal = min(minVal, L - nowY + 1);
		}
		else if (newY < -L) {
			minVal = min(minVal, L + nowY + 1);
		}

		for (int j = 0; v.size() > 0 && j < v.size() - 1; j++) {
			long long startX = v[j].startX;
			long long startY = v[j].startY;
			long long endX = v[j].endX;
			long long endY = v[j].endY;
			long long length = v[j].length;
			long long dir = v[j].dir;

			if (nowDir == 0) {
				if (dir == 0 && startX == nowX && nowY <= startY && startY <= newY) {
					minVal = min(minVal, startY - nowY);
				}
				else if (dir == 1 && startX <= nowX && nowX <= endX && nowY <= startY && startY <= newY) {
					minVal = min(minVal, startY - nowY);
				}
				else if (dir == 2 && startX == nowX && nowY <= endY && endY <= newY) {
					minVal = min(minVal, endY - nowY);
				}
				else if (dir == 3 && endX <= nowX && nowX <= startX && nowY <= endY && endY <= newY)
					minVal = min(minVal, endY - nowY);
			}
			else if (nowDir == 1) {
				if (dir == 0 && nowX <= startX && startX <= newX && startY <= nowY && nowY <= endY) {
					minVal = min(minVal, endX - nowX);
				}
				else if (dir == 1 && nowY == startY && nowX <= startX && startX <= newX) {
					minVal = min(minVal, startX - nowX);
				}
				else if (dir == 2 && nowX <= startX && startX <= newX && endY <= newY && newY <= startY) {
					minVal = min(minVal, startX - nowX);
				}
				else if (dir == 3 && nowY == startY && nowX <= endX && endX <= newX) {
					minVal = min(minVal, endX - nowX);
				}
			}
			else if (nowDir == 2) {
				if (dir == 0 && nowX == startX && newY <= endY && endY <= nowY) {
					minVal = min(minVal, nowY - endY);
				}
				else if (dir == 1 && startX <= nowX && nowX <= endX && newY <= startY && startY <= nowY) {
					minVal = min(minVal, nowY - endY);
				}
				else if (dir == 2 && nowX == startX && newY <= startY && startY <= nowY) {
					minVal = min(minVal, nowY - startY);
				}
				else if (dir == 3 && newY <= startY && startY <= nowY && endX <= nowX && nowX <= startX) {
					minVal = min(minVal, nowY - startY);
				}
			}
			else if (nowDir == 3) {
				if (dir == 0 && startY <= nowY && nowY <= endY && newX <= endX && endX <= nowX) {
					minVal = min(minVal, nowX - startX);
				}
				else if (dir == 1 && startY == nowY && newX <= endX && endX <= nowX) {
					minVal = min(minVal, nowX - endX);
				}
				else if (dir == 2 && newX <= startX && startX <= nowX && endY <= nowY && nowY <= startY) {
					minVal = min(minVal, nowX - endX);
				}
				else if (dir == 3 && startY == nowY && newX <= startX && startX <= nowX) {
					minVal = min(minVal, nowX - startX);
				}
			}
		}

		if (minVal == LLONG_MAX) {
			line lineValue;

			lineValue.startX = nowX;
			lineValue.startY = nowY;
			lineValue.length = t;
			lineValue.dir = nowDir;
			lineValue.endX = lineValue.startX + lineValue.length * dx[lineValue.dir];
			lineValue.endY = lineValue.startY + lineValue.length * dy[lineValue.dir];
			v.push_back(lineValue);

			nowX = newX;
			nowY = newY;

			if (dirChar == 'R') {
				nowDir = (nowDir + 1) % 4;
			}
			else {
				nowDir = (nowDir + 3) % 4;
			}

			ans += t;
		}
		else {
			finishFlag = true;
			ans += minVal;
		}
	}

	cout << ans << "\n";

	return 0;
}