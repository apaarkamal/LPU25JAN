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

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    } cout << '\n';
}


// whether it is inplace ?? ->  inplace
// is it stable?? -> yes it is
// worst case - O(n^2)
// best case - O(n^2)
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        // db(i, min_idx);
        swap(a[i], a[min_idx]);
    }
}

// stable?? - true
// inplace?? - yes
// Best Case - O(n)
// worst case - O(n^2)
void bubbleSort(int a[], int n) {
    int swp = 1;
    while (swp) {
        swp = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swp++;
            }
        }
        // print(a, n);
    }
}

// stable - stable
// inplace - true
// worst - O(n^2)
// best - O(n)
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        // insert a[i] at the right place

        int j = i - 1;
        int val = a[i];
        while (j >= 0 && a[j] > val) {
            a[j + 1] = a[j];
            j--;
        }

        // insert the val
        a[j + 1] = val;
    }
}

// not stable
// not inplace
// worst - max(n, mx)
// best - max(n, mx)
// space complexity - max(n, mx)
void countSort(int a[], int n) {
    int mx = *max_element(a, a + n);
    int count[mx + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    for (int i = 0, j = 0; i <= mx; i++) {
        while (count[i]--) {
            a[j] = i;
            j++;
        }
    }
}

void countSortStable(int a[], int n) {
    int mx = *max_element(a, a + n);
    vector<int> count[mx + 1];
    for (int i = 0; i < n; i++) {
        count[a[i]].push_back(a[i]);
    }
    for (int i = 0, j = 0; i <= mx; i++) {
        for (auto x : count[i]) {
            a[j] = x;
            j++;
        }
    }
}

int maxDigits(int mx) {
    string s = to_string(mx);
    return (int)s.size();
}

// O(n)
void sortCountForLevel(int a[], int n, int level) {
    vector<int> count[10];

    // count[0] is a vector

    for (int i = 0; i < n; i++) {
        int digit = (int)(a[i] / pow(10, level)) % 10;
        count[digit].push_back(a[i]);
    }

    for (int i = 0, j = 0; i <= 9; i++) {
        for (auto x : count[i]) {
            a[j] = x;
            j++;
        }
    }
}

// integer - 9 * o(n)
// long integer - 18 * o(n)
void radixSort(int a[], int n) {
    int mx_levels = maxDigits(*max_element(a, a + n));

    // O(n) * mx_levels
    for (int i = 0; i < mx_levels; i++) {
        sortCountForLevel(a, n, i);
    }
}

void mergeTwoSortedArrays(int a[], int left, int mid, int right) {
    // db(left, right);
    // two partitions
    // first partition is left - mid
    // second partition is mid+1 - right
    int m = right - left + 1;
    int c[m];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) {
            c[k] = a[i];
            k++; i++;
        }
        else {
            c[k] = a[j];
            j++; k++;
        }
    }

    while (i <= mid) {
        c[k] = a[i];
        k++; i++;
    }
    while (j <= right) {
        c[k] = a[j];
        j++; k++;
    }

    // I have to copy c array back to the a array
    k = 0;
    while (left <= right) {
        a[left] = c[k];
        left++; k++;
    }
}


// stable - true
// in-place - not in place
// worst - nlogn
// best - nlogn
void mergeSortHelper(int a[], int left, int right) {
    // db(left, right);
    if (left == right) {
        return;
    }

    int mid = (left + right) / 2;

    // sort the left array
    mergeSortHelper(a, left, mid);
    mergeSortHelper(a, mid + 1, right);

    // mergeTwoSortedArrays
    mergeTwoSortedArrays(a, left, mid, right);
}

void mergeSort(int a[], int n) {
    mergeSortHelper(a, 0, n - 1);
}

int pickPivot(int a[], int left, int right) {
    // picks the pivot
    int pivot_element = a[right];
    // put the pivot on the correct place
    int i, j;
    for (i = left, j = left; j < right; j++) {
        if (a[j] < pivot_element) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[right]);
    return i;
}

void quickSort(int a[], int left, int right) {
    if (left >= right) return;
    // cout << '\n';
    // db(left, right);
    // print(a, 8);
    int pivot_index = pickPivot(a, left, right);
    // db(pivot_index);
    // print(a, 8);
    // cout << '\n';

    quickSort(a, left, pivot_index - 1);
    quickSort(a, pivot_index + 1, right);
}

// worst case - O(n^2)
// best case - O(nlogn)
// stable - not stable
// inplace - true
void quickSort(int a[], int n) {
    quickSort(a, 0, n - 1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // selectionSort(a, n);
    // bubbleSort(a, n);
    // insertionSort(a, n);
    // countSort(a, n);
    // countSortStable(a, n);
    // radixSort(a, n);
    // mergeSort(a, n);
    quickSort(a, n);
    print(a, n);


}