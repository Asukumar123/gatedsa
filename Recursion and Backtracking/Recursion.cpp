
#include <iostream>
using namespace std;

// A simple recursive function to calculate sum of numbers from 1 to n
int Sum(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }
    // Recursive case
    return n + Sum(n - 1);
}   


int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    if (number < 0) {
        cout << "Sum is not defined for negative numbers." << endl;
    } else {
        int result = Sum(number);
        cout << "Sum of numbers from 1 to " << number << " is " << result << endl;
    }

    return 0;
}
// This program calculates the sum of numbers from 1 to a given positive integer using recursion.