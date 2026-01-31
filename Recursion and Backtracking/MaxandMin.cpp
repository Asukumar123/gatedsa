#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int mn;
    int mx;
};

Pair getMinMax(int arr[], int low, int high) {
    Pair ans, left, right;

    // Base case: one element
    if (low == high) {
        ans.mn = arr[low];
        ans.mx = arr[low];
        return ans;
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            ans.mn = arr[low];
            ans.mx = arr[high];
        } else {
            ans.mn = arr[high];
            ans.mx = arr[low];
        }
        return ans;
    }

    // Divide
    int mid = (low + high) / 2;

    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);

    // Combine
    ans.mn = min(left.mn, right.mn);   // 1 comparison
    ans.mx = max(left.mx, right.mx);   // 1 comparison

    return ans;
}

int main() {
    int arr[] = {3, 5, 1, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    Pair res = getMinMax(arr, 0, n - 1);
    cout << "Min = " << res.mn << endl;
    cout << "Max = " << res.mx << endl;
}
