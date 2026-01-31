#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

// Sort items by value/weight ratio (descending)
bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, cmp);   // sort by profit/weight ratio

    double profit = 0.0;

    for(int i = 0; i < n; i++) {
        if(arr[i].weight <= W) {   // take full item
            W -= arr[i].weight;
            profit += arr[i].value;
        } else {                  // take fraction
            profit += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return profit;
}

int main() {
    Item arr[] = {{60,10}, {100,20}, {120,30}};
    int W = 50;
    int n = 3;

    cout << fractionalKnapsack(W, arr, n);
    return 0;
}
