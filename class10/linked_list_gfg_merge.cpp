// https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
public:
	// Function which returns the  root of the flattened linked list.
	Node *flatten(Node *root) {
		if (root == NULL) return root;
		// Your code here
		// int -> data in negative
		priority_queue<pair<int, Node*>> Q;

		Q.push(make_pair(-root->data, root));

		Node* head = NULL;
		Node* tail = NULL;

		while (!Q.empty()) {
			pair<int, Node*> cur = Q.top();
			Q.pop();
			Node* curnode = cur.second;

			if (curnode->next) {
				Q.push(make_pair(-curnode->next->data, curnode->next));
			}
			if (curnode->bottom) {
				Q.push(make_pair(-curnode->bottom->data, curnode->bottom));
			}

			if (head == NULL) {
				head = curnode;
				tail = curnode;
			}
			else {
				tail->bottom = curnode;
				tail = curnode;
			}

		}
		return head;
	}
};