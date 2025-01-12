// Problem statement
// You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.



// For Example
// 'N' = 3, 'K' = 5, 'A' = [1, 2, 3].
// Subset [2, 3] has sum equal to 'K'.
// So our answer is True.

#include <bits/stdc++.h>

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    // DP array to store results for all sums up to k
    vector<bool> dp(k + 1, false);

    // Base case: A sum of 0 can always be achieved
    dp[0] = true;

    // Process each element in the array
    for (int num : a) {
        // Update dp array in reverse to avoid overwriting
        for (int j = k; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    // The result is stored in dp[k]
    return dp[k];
}