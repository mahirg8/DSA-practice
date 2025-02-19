// Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

// Example:

// Input: heights[] = [20, 30, 40, 20] 
// Output: 20
// Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
// jump from stair 0 to 1: cost = |30 - 20| = 10
// jump from stair 1 to 3: cost = |20-30|  = 10
// Total Cost = 10 + 10 = 20

#include <bits/stdc++.h> 
int f(int ind, vector<int> &height, vector<int> &dp){
        if(ind==0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int left = f(ind-1, height, dp) + abs(height[ind] - height[ind-1]);
        int right = INT_MAX;
        if(ind > 1) right = f(ind-2, height, dp) + abs(height[ind] - height[ind-2]);
        return dp[ind] = min(left, right);
    }
int frogJump(int n, vector<int> &height)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
        return f(n-1, height, dp);
}