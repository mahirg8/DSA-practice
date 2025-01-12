// Perfect Sum Problem

// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

// Examples:

// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.


const int MOD = 1e9 + 7;
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: There's one way to make sum 0
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            // Exclude the current element
            dp[i][j] = dp[i-1][j];
            // Include the current element if it doesn't exceed the target
            if (arr[i-1] <= j) {
                dp[i][j] = (dp[i][j] + dp[i-1][j - arr[i-1]]) % MOD;
            }
        }
    }

    // The result is in dp[n][target]
    return dp[n][target];
    }