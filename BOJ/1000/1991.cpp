#include <iostream>
#include <string>
using namespace std;

struct node {
	char left;
	char right;
};

node tree[26];

void pre(char root) {
	if (root == '.')
		return;
	else {
		cout << root;
		pre(tree[root - 'A'].left);
		pre(tree[root - 'A'].right);
	}
}

void in(char root) {
	if (root == '.')
		return;
	else {
		in(tree[root - 'A'].left);
		cout << root;
		in(tree[root - 'A'].right);
	}
}

void post(char root) {
	if (root == '.')
		return;
	else {
		post(tree[root - 'A'].left);
		post(tree[root - 'A'].right);
		cout << root;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		char data;
		char left;
		char right;
		cin >> data >> left >> right;

		tree[data - 'A'].left = left;
		tree[data - 'A'].right = right;
	}

	pre('A');
	cout << "\n";
	in('A');
	cout << "\n";
	post('A');
	cout << "\n";
}