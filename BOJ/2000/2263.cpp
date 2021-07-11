#include <iostream>
#include <algorithm>
using namespace std;

int n;

int inOrder[100001];
int postOrder[100001];
int index[100001];

void preOrder(int inStart, int inEnd, int postStart, int postEnd) {
	if (inStart > inEnd || postStart > postEnd) {
		return;
	}

	int root = postOrder[postEnd];

	cout << root << " ";

	preOrder(inStart, inEnd - 1, postStart, postStart + index[root] - inStart - 1);
	preOrder(index[root] + 1, inEnd, postStart + index[root] - inStart, postEnd - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> inOrder[i];
		index[inOrder[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> postOrder[i];
	}

	preOrder(1, n, 1, n);

	return 0;
}