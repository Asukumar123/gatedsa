#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store job details
struct Job {
    int id;       // Job ID
    int deadline; // Deadline of job
    int profit;   // Profit if job is done before deadline
};

// Comparator to sort jobs by decreasing profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    // Example jobs
    vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 10},
        {3, 2, 27},
        {4, 1, 15}
    };

    int n = jobs.size();

    // Step 1: Sort jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    // Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    // Create time slots (initially empty)
    vector<int> slot(maxDeadline + 1, -1); // -1 means empty slot

    int totalProfit = 0;

    // Step 2: Assign jobs to the latest possible free slot
    for (int i = 0; i < n; i++) {
        // Try to find a free slot from job's deadline backwards
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;  // Assign job
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print selected jobs
    cout << "Selected Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (slot[i] != -1)
            cout << "J" << slot[i] << " ";
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
