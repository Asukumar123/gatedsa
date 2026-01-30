#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int st, int en) {
    int pivot = arr[en];
    int idx = st - 1;

    for (int j = st; j < en; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }

    idx++;
    swap(arr[idx], arr[en]);
    return idx;
}

void quickSort(vector<int>& arr, int st, int en) {
    if (st < en) {
        int pividx = partition(arr, st, en);
        quickSort(arr, st, pividx - 1);
        quickSort(arr, pividx + 1, en);
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
