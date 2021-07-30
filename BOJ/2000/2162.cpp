#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Coord {
	int x1;
	int y1;
	int x2;
	int y2;
};

vector<Coord> line;
vector<int> root; //root & group member cnt
vector<int> groupMemCnt;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int ccwAns = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);

	if (ccwAns > 0) {
		return 1;
	}
	else if (ccwAns < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

bool checkCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 && ccw(x1, y1, x3, y3, x4, y4) * ccw(x2, y2, x3, y3, x4, y4) <= 0) {
		if (x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) {
			return false;
		}
		else if (x3 > x1 && x4 > x1 && x3 > x2 && x4 > x2) {
			return false;
		}
		else if (y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) {
			return false;
		}
		else if (y3 > y1 && y4 > y1 && y3 > y2 && y4 > y2) {
			return false;
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

int getRoot(int a) {
	if (root[a] == a) {
		return a;
	}
	else {
		root[a] = getRoot(root[a]);

		return root[a];
	}
}

void makeGroup(int a, int b) {
	root[getRoot(a)] = getRoot(b);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	line.resize(N + 1);
	root.resize(N + 1);
	groupMemCnt.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> line[i].x1 >> line[i].y1 >> line[i].x2 >> line[i].y2;

		root[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (checkCross(line[i].x1, line[i].y1, line[i].x2, line[i].y2, line[j].x1, line[j].y1, line[j].x2, line[j].y2)) {
				makeGroup(i, j);
			}
		}
	}

	//cout << "Group Member Count\n";
	for (int i = 1; i <= N; i++) {
		//cout << i << " " << group[getRoot(i)].second << "\n";
		groupMemCnt[getRoot(i)]++;
	}

	int countGroup = 0;

	for (int i = 1; i <= N; i++) {
		if (groupMemCnt[i] > 0) {
			countGroup++;
		}
	}

	cout << countGroup << "\n";
	cout << *max_element(groupMemCnt.begin(), groupMemCnt.end());

	return 0;
}