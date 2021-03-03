#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insert(Node* node, const int& data) {
	if (node == NULL) {
		node = new Node;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else if (data < node->data) {
		node->left = insert(node->left, data);
	}
	else {
		node->right = insert(node->right, data);
	}

	return node;
}

void post(Node* node) {
	if (node->left != NULL) {
		post(node->left);
	}
	if (node->right != NULL) {
		post(node->right);
	}
	cout << node->data << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	Node* root = NULL;
	int data;

	while (cin >> data) {
		root = insert(root, data);
	}

	post(root);

	return 0;
}