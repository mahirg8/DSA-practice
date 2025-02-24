// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

class Solution {
    public:
        int f(int i, int j, vector<vector<int> > &triangle, int n,
                           vector<vector<int> > &dp) {
        // If the result for this cell is already calculated, return it
        if (dp[i][j] != -1)
            return dp[i][j];
    
        // If we're at the bottom row, return the value of the current cell
        if (i == n - 1)
            return triangle[i][j];
    
        // Calculate the sum of two possible paths: going down and going diagonally
        int down = triangle[i][j] + f(i + 1, j, triangle, n, dp);
        int diagonal = triangle[i][j] + f(i + 1, j + 1, triangle, n, dp);
    
        // Store the minimum of the two paths in the dp table and return it
        return dp[i][j] = min(down, diagonal);
    }
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
           
            vector<vector<int>> dp(n, vector<int>(n, -1));
    
            return f(0, 0, triangle, n, dp);
    
        }
    };