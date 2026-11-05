
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

struct Node {
    int level;
    int profit;
    int weight;
    double bound;
};

// Sort items according to value/weight ratio
bool compareItems(Item a, Item b) {
    return a.ratio > b.ratio;
}

// ---------------- DYNAMIC PROGRAMMING ----------------

int knapsackDP(int W, vector<Item>& items) {

    int n = items.size();

    // Create DP table initialized with 0
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Consider each item one by one
    for(int i = 1; i <= n; i++) {

        // Check every possible capacity
        for(int w = 1; w <= W; w++) {

            // If item weight is within current capacity
            if(items[i - 1].weight <= w) {

                // Choose maximum of including or excluding item
                dp[i][w] = max(
                    dp[i - 1][w],
                    items[i - 1].value +
                    dp[i - 1][w - items[i - 1].weight]
                );
            }
            else {

                // Cannot include item, so skip it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return maximum profit
    return dp[n][W];
}

// ---------------- BRANCH AND BOUND ----------------

// Calculate upper bound for a node
double bound(Node u, int n, int W, vector<Item>& items) {

    // If capacity is already full or exceeded
    if(u.weight >= W)
        return 0;

    double profit_bound = u.profit;

    int j = u.level + 1;
    int totalWeight = u.weight;

    // Add complete items while capacity allows
    while(j < n && totalWeight + items[j].weight <= W) {

        totalWeight += items[j].weight;
        profit_bound += items[j].value;

        j++;
    }

    // Add fractional part of next item for upper bound
    if(j < n) {
        profit_bound += (W - totalWeight) * items[j].ratio;
    }

    return profit_bound;
}

// Solve knapsack using Branch and Bound
int knapsackBnB(int W, vector<Item>& items) {

    int n = items.size();

    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compareItems);

    // Queue to store nodes
    queue<Node> Q;

    Node u, v;

    // Initial root node
    u = {-1, 0, 0, 0};

    Q.push(u);

    int maxProfit = 0;

    // Explore nodes until queue becomes empty
    while(!Q.empty()) {

        u = Q.front();
        Q.pop();

        // Check if all items are processed
        if(u.level == n - 1)
            continue;

        // Move to next level
        v.level = u.level + 1;

        // -------- INCLUDE CURRENT ITEM --------

        v.weight = u.weight + items[v.level].weight;

        v.profit = u.profit + items[v.level].value;

        // Update maximum profit if weight is valid
        if(v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        // Calculate bound
        v.bound = bound(v, n, W, items);

        // Add node only if it can improve maximum profit
        if(v.bound > maxProfit) {
            Q.push(v);
        }

        // -------- EXCLUDE CURRENT ITEM --------

        v.weight = u.weight;
        v.profit = u.profit;

        // Calculate bound without including current item
        v.bound = bound(v, n, W, items);

        // Add node if it has a chance of better profit
        if(v.bound > maxProfit) {
            Q.push(v);
        }
    }

    return maxProfit;
}

// ---------------- MAIN FUNCTION ----------------

int main() {

    int W = 50;

    // Items: {weight, value, ratio}
    vector<Item> items = {
        {10, 60, 0},
        {20, 100, 0},
        {30, 120, 0}
    };

    // Calculate value/weight ratio
    for(auto &item : items) {
        item.ratio = (double)item.value / item.weight;
    }

    int choice;

    cout << "0-1 Knapsack Problem\n";
    cout << "1. Dynamic Programming\n";
    cout << "2. Branch and Bound\n";

    cout << "Enter your choice: ";
    cin >> choice;

    if(choice == 1) {

        int ans = knapsackDP(W, items);

        cout << "Maximum value using DP: " << ans << endl;
    }
    else if(choice == 2) {

        int ans = knapsackBnB(W, items);

        cout << "Maximum value using BnB: " << ans << endl;
    }
    else {

        cout << "Invalid choice!";
    }

    return 0;
}
