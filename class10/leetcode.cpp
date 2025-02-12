#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

node* constructLL() {
    node* head = NULL;
    node* tail = NULL;

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        node* temp = new node(x);
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    return head;
}

void printLL(node* head) {
    node* cur = head;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << '\n';
}

node* insertAtHead(node* head, int data) {
    node* temp = new node(data);
    if (head == NULL) {
        return temp;
    }
    else {
        temp->next = head;
        return temp;
    }
}

node* fetchTail(node* head) {
    node* cur = head;
    while (cur->next) {
        cur = cur->next;
    }
    return cur;
}

node* insertAtTail(node* head, int data) {
    if (head == NULL) {
        return insertAtHead(head, data);
    }

    node* cur = fetchTail(head);
    // cur is pointing to the last node
    node* temp = new node(data);
    cur->next = temp;
    return head;
}

node* insertAtKth(node* head, int k, int data) {
    if (k == 1) {
        return insertAtHead(head, data);
    }

    node* cur = head;
    k -= 2;
    while (k--) {
        cur = cur->next;
    }

    node* temp = new node(data);
    temp->next = cur->next;
    cur->next = temp;

    return head;
}

int findLengthOfLL(node* head) {
    int cnt = 0;
    node* cur = head;
    while (cur) {
        cur = cur->next;
        cnt++;
    }
    return cnt;
}

node* leftShiftLL(node* head, int k) {
    k %= findLengthOfLL(head);

    node* tail = fetchTail(head);
    tail->next = head;

    node* cur = head;
    k--;
    while (k--) {
        cur = cur->next;
    }

    head = cur->next;
    cur->next = NULL;
    return head;
}

node* rightShiftLL(node* head, int k) {
    return leftShiftLL(head, findLengthOfLL(head) - k);
}

node* deleteAtHead(node* head) {
    if (head == NULL) return head;
    node* newHead = head->next;
    delete head;
    return newHead;
}

node* deleteAtTail(node* head) {
    node* cur = head;

    while (cur->next != NULL && cur->next->next != NULL) {
        cur = cur->next;
    }

    // cur is tail - 1
    node* tail = cur->next;
    delete tail;

    cur->next = NULL;

    return head;
}

node* deleteAtKth(node* head, int k) {
    if (k == 1) {
        return deleteAtHead(head);
    }
    if (k == findLengthOfLL(head)) {
        return deleteAtTail(head);
    }

    node *cur = head;
    k--; k--;
    while (k--) {
        cur = cur->next;
    }
    // k-1 th
    node* to_be_deleted = cur->next;
    cur->next = cur->next->next;
    delete to_be_deleted;
    return head;
}

node* reverse(node* head) {
    node* cur = head;
    node* prev = NULL;
    while (cur) {
        node* forward = cur->next;
        cur->next = prev;
        prev = cur;
        cur = forward;
    }
    return prev;
}

node* reverseUsingRecursion(node* cur, node* prev = NULL) {
    if (cur == NULL) return prev;
    node* forward = cur->next;
    cur->next = prev;
    return reverseUsingRecursion(forward, cur);
}

node* mergeTwoLists(node* head1, node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    if (head1->data < head2->data) {
        head1->next = mergeTwoLists(head1->next, head2);
        return head1;
    }
    else {
        head2->next = mergeTwoLists(head1, head2->next);
        return head2;
    }
}

node* midPoint(node* head) {
    if (findLengthOfLL(head) <= 2) return head;

    node* slow = head;
    node* fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// O(nlogn)
node* mergeSort(node* head) {
    if (head == NULL) return head;
    if (head->next == NULL) return head;

    node* mid = midPoint(head);
    node* head1 = head;
    node* head2 = mid->next;

    mid->next = NULL;

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    return mergeTwoLists(head1, head2);
}

bool isCycle(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            // cout << slow->data << '\n';
            return true;
        }
    }

    return false;
}

node* detectCyclicNode(node* head) {
    node* slow = head;
    node* fast = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
    }

    // slow = fast is meeting node
    slow = head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // slow = fast is the cyclic node
    return slow;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    node* head = constructLL();

    printLL(head);

    head = insertAtHead(head, 5);

    printLL(head);

    head = insertAtTail(head, 10);

    printLL(head);

    head = insertAtKth(head, 4, 20);
    head = insertAtKth(head, 7, 3);

    printLL(head);

    // cout << findLengthOfLL(head) << '\n';

    head = leftShiftLL(head, 3);

    printLL(head);

    head = leftShiftLL(head, 6);

    printLL(head);

    head = rightShiftLL(head, 2);

    printLL(head);

    head = deleteAtHead(head);

    printLL(head);

    head = deleteAtTail(head);
    head = deleteAtTail(head);

    printLL(head);

    head = deleteAtKth(head, 4);

    printLL(head);

    head = deleteAtKth(head, 5);

    printLL(head);

    head = reverse(head);

    printLL(head);

    head = reverseUsingRecursion(head);

    printLL(head);

    cout << midPoint(head)->data << '\n';

    head = mergeSort(head);

    printLL(head);

    node* tail = fetchTail(head);
    tail->next = head->next;

    // cout << isCycle(head) << '\n';

    cout << detectCyclicNode(head)->data << '\n';















}