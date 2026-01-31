#include <iostream>
using namespace std;

// Function to compute a^n using fast power (divide & conquer)
// Time Complexity: O(log n)
// Space Complexity: O(log n)  (due to recursion)

long long power(long long a, long long n)
{
    if (n == 0) return 1;              // base case

    long long p = power(a, n / 2);    // recursive call

    if (n % 2 == 0)
        return p * p;                 // if n is even
    else
        return p * p * a;             // if n is odd
}

int main()
{
    long long a, n;
    cin >> a >> n;                    // input base and power
    cout << power(a, n);              // print result
    return 0;
}
