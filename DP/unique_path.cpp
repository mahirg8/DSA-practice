// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:


// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

class Solution {
    public:
        int countWaysUtil(int i, int j, vector<vector<int>>& dp) {
        // Base case: If we reach the top-left corner (0, 0), there is one way.
        if (i == 0 && j == 0)
            return 1;
    
        // If we go out of bounds or reach a blocked cell, there are no ways.
        if (i < 0 || j < 0)
            return 0;
    
        // If we have already computed the number of ways for this cell, return it.
        if (dp[i][j] != -1)
            return dp[i][j];
    
        // Calculate the number of ways by moving up and left recursively.
        int up = countWaysUtil(i - 1, j, dp);
        int left = countWaysUtil(i, j - 1, dp);
    
        // Store the result in the dp table and return it.
        return dp[i][j] = up + left;
    }
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, -1));
    
        // Call the utility function with the bottom-right cell as the starting point.
        return countWaysUtil(m - 1, n - 1, dp);
        }
    };