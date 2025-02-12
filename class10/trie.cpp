#include<bits/stdc++.h>
using namespace std;

struct node {
    node* child[26];
    bool is_end;
    int cnt;
    node() {
        for (int i = 0; i < 26; i++) {
            this->child[i] = NULL;
        }
        is_end = false;
        cnt = 0;
    }
};

void insertIntoTrie(node* root, string s) {
    node* cur = root;
    cur->cnt++;
    for (int i = 0; i < s.size(); i++) {
        int index = s[i] - 'a';
        if (cur->child[index] == NULL) {
            cur->child[index] = new node();
        }
        cur = cur->child[index];
        cur->cnt++;
    }
    cur->is_end = true;
    return;
}

bool searchInTrie(node* root, string s) {
    node* cur = root;
    for (int i = 0; i < s.size(); i++) {
        int index = s[i] - 'a';
        if (cur->child[index] == NULL) return false;
        cur = cur->child[index];
    }
    return cur->is_end;
}

// O(size(prefix))
int countStringsWithPrefix(node* root, string prefix) {
    node* cur = root;
    for (int i = 0; i < prefix.size(); i++) {
        int index = prefix[i] - 'a';
        if (cur->child[index] == NULL) return 0;
        cur = cur->child[index];
    }
    return cur->cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    node* root = new node();
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        insertIntoTrie(root, s);
    }


    // cout << (searchInTrie(root, "aayushi") ? "found" : "not found");

    cout << countStringsWithPrefix(root, "m");





}