// Given an array of positive integers arr[] and a value target, determine if there is a subset of the given array with sum equal to given target. 

// Examples:

// Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
// Output: true 
// Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

bool f(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0) return true;
    if(ind==0) return (arr[0] == target);
    
    if(dp[ind][target] != -1) return dp[ind][target];
    
    bool nottake = f(ind-1, target, arr, dp);
    bool take = false;
    
    if(target >= arr[ind]){
        take = f(ind-1, target-arr[ind], arr, dp);
    }
    return dp[ind][target] = take | nottake;
}
bool isSubsetSum(vector<int>& arr, int target) {
    // code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return f(n-1, target, arr, dp);
}