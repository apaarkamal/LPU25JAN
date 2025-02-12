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
	int val, height;
	node* left;
	node* right;
	node(int val) {
		this->val = val;
		this->height = 1;
		this->left = this->right = NULL;
	}
};

int height(node* root) {
	if (root == NULL) return 0;
	return root->height;
}

// -1, 0, 1 -> balanced nodes
int balanceFactor(node* root) {
	return height(root->left) - height(root->right);
}

void inOrder(node* root) {
	if (root == NULL) return;
	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}



bool searchInAVL(node* root, int val) {
	if (root == NULL) return false;
	if (root->val == val) return true;
	if (val < root->val) {
		return searchInAVL(root->left, val);
	}
	else {
		return searchInAVL(root->right, val);
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

bool isBalanced(node* root) {
	if (root == NULL) return true;
	return (abs(height(root->left) - height(root->right)) <= 1)
	       && isBalanced(root->left)
	       && isBalanced(root->right);
}

node* leftRotate(node* root) {
	cout << "left\n";
	node* right_child = root->right;
	node* right_left_child = right_child->left;
	right_child->left = root;
	root->right = right_left_child;
	// height of node needs to be updated.
	root->height = 1 + max(height(root->left), height(root->right));
	right_child->height = 1 + max(height(right_child->left), height(right_child->right));
	return right_child;
}

node* rightRotate(node* root) {
	cout << "right\n";
	node* left_child = root->left;
	node* left_right_child = left_child->right;
	left_child->right = root;
	root->left = left_right_child;
	// update height
	root->height = 1 + max(height(root->left), height(root->right));
	left_child->height = 1 + max(height(left_child->left), height(left_child->right));
	return left_child;
}

node* insertInAVL(node* root, int val) {
	if (root == NULL) return new node(val);
	if (val < root->val) {
		root->left = insertInAVL(root->left, val);
	}
	if (val > root->val) {
		root->right = insertInAVL(root->right, val);
	}
	if (val == root->val) {
		return root;
	}
	// check whether the current node is balanced
	root->height = 1 + max(height(root->left), height(root->right));
	if (balanceFactor(root) > 1 && balanceFactor(root->left) >= 0) {
		// LL
		// right rotation on root
		return rightRotate(root);
	}
	if (balanceFactor(root) < -1 && balanceFactor(root->right) <= 0) {
		// RR
		// left rotation on root
		return leftRotate(root);
	}
	if (balanceFactor(root) > 1 && balanceFactor(root->left) < 0) {
		// LR
		// left rotation on child node
		root->left = leftRotate(root->left);
		// right rotation on root node
		return rightRotate(root);
	}
	if (balanceFactor(root) < -1 && balanceFactor(root->right) > 0) {
		// RL
		// right rotation on the child
		root->right = rightRotate(root->right);
		// left rotation on the root node
		return leftRotate(root);
	}
	return root;
}

node* build_avl() {
	int x;
	cin >> x;
	node* root = NULL;
	while (x != -1) {
		root = insertInAVL(root, x);
		printLevelOrder(root); cout << '\n' << '\n';
		cin >> x;
	}
	return root;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node* root = build_avl();

	// inOrder(root);

	// cout << searchInBST(root, 9);

	// printLevelOrder(root);

	// root = deleteFromBST(root, 3);
	// cout << '\n';
	// cout << '\n';


	// printLevelOrder(root);


	// cout << isBalanced(root) << '\n';










}