#include<bits/stdc++.h>
using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

struct node {
	int val;
	node* left;
	node* right;
	node(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};

node* insertInBST(node* root, int val) {
	if (root == NULL) return new node(val);
	if (val < root->val) {
		root->left = insertInBST(root->left, val);
	}
	if (val > root->val) {
		root->right = insertInBST(root->right, val);
	}
	return root;
}

node* build_bst() {
	int x;
	cin >> x;
	node* root = NULL;
	while (x != -1) {
		root = insertInBST(root, x);
		cin >> x;
	}
	return root;
}

void inOrder(node* root) {
	if (root == NULL) return;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}

bool searchInBST(node* root, int val) {
	if (root == NULL) return false;
	if (root->val == val) return true;
	if (val < root->val) {
		return searchInBST(root->left, val);
	}
	else {
		return searchInBST(root->right, val);
	}
}

void printLevelOrder(node* root) {
	if (root == NULL) return;
	queue<node*> Q;
	Q.push(root);
	Q.push(NULL);
	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		if (cur == NULL) {
			if (!Q.empty()) {
				Q.push(NULL);
				cout << '\n';
			}
		}
		else {
			cout << cur->val << " ";
			if (cur->left) {
				Q.push(cur->left);
			}
			if (cur->right) {
				Q.push(cur->right);
			}
		}
	}
}

// delete node from BST
node* deleteFromBST(node* root, int val) {
	if (root == NULL) return NULL;
	if (val < root->val) {
		root->left = deleteFromBST(root->left, val);
		return root;
	}
	else if (val > root->val) {
		root->right = deleteFromBST(root->right, val);
		return root;
	}
	else {
		// val == root->val
		// we are on the node to be deleted
		if (root->left == NULL && root->right == NULL) {
			// its a leaf node
			return NULL;
		}
		else if (root->left != NULL && root->right == NULL) {
			// single parent
			return root->left;
		}
		else if (root->right != NULL && root->left == NULL) {
			// single parent
			return root->right;
		}
		else {
			// both left and right are not null
			// two child parent case
			node* left_sub = root->left;
			node* right_sub = root->right;
			node* temp = left_sub;
			while (temp -> right) {
				temp = temp -> right;
			}
			temp->right = right_sub;
			return left_sub;
		}
	}
}

int height(node* root) {
	if (root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(node* root) {
	if (root == NULL) return true;
	return (abs(height(root->left) - height(root->right)) <= 1)
	       && isBalanced(root->left)
	       && isBalanced(root->right);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = build_bst();

	// inOrder(root);

	// cout << searchInBST(root, 9);

	// printLevelOrder(root);

	// root = deleteFromBST(root, 3);
	// cout << '\n';
	// cout << '\n';


	// printLevelOrder(root);


	cout << isBalanced(root) << '\n';










}