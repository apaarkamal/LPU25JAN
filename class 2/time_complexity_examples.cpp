#include<bits/stdc++.h>
using namespace std;

void fun(int a, int b) {
    //
    while (a != b) {
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // O(n)
    for (i = 0; i < n; i++) {

    }


    // O(m*n)
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {

        }
    }

    // O(n)
    for (i = 0; i < n; i += 2) {

    }

    // infinite loop
    for (i = 0; i < n; i *= 2) {

    }

    // O(log2(n))
    for (i = 1; i < n; i *= 2) {

    }

    // time complexity??
    // log3(n)
    for (i = n; i >= 1; i /= 3) {

    }

    // O(sqrt(n))
    for (i = 0; i * i <= n; i++) {

    }

    // O(sqrt(n)/3)
    for (i = 0; i * i <= n; i = i + 3) {

    }


    // O(n)
    // O(n/k) * O(k) =  O(n)
    // for some k < n;
    for (int i = 1; i <= n; ) { // O(n/k)
        for (int j = 1; j <= k; j++) { // O(k)
            cout << "here";
        }
        i = i + k
    }

    // O(n*n)
    for (int i = 1; i <= n; i++) { // O(n)
        for (int j = i; j >= 1; j--) { // O(i)
            cout << "here";
        }
    }

    // O(nlog(n))
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            cout << "here";
        }
    }

    // O(n*n*n)
    for (int i = 0; i < n / 2; i++) { // O(n/2)
        for (int j = 1; j + n / 2 < n; j++) { // O(n/2)
            for (int k = 1; k <= n; k++) { // O(n)

            }
        }
    }








}