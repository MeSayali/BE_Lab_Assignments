
#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];

            if (wt[i - 1] <= w)
                dp[i][w] = max(dp[i][w],
                    val[i - 1] + dp[i - 1][w - wt[i - 1]]);
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter weight and value: ";
        cin >> wt[i] >> val[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> W;

    cout << "Maximum value: " << knapsack(wt, val, n, W) << "\n";

    return 0;
}
