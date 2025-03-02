// Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

// Examples :

// Input: arr[] =  [5, 2, 6, 4], d = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

int f(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp){
    if(ind==0){
        if(sum==0 && arr[0]==0) return 2;
        if(sum==0 || sum==arr[0]) return 1;
        return 0;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];
    
    int nottake = f(ind-1, sum, arr, dp);
    int take = 0;
    if(arr[ind] <= sum) take = f(ind-1, sum-arr[ind], arr, dp);
    
    return dp[ind][sum] = (nottake + take)%mod;
}
int findways(vector<int>& arr, int tar){
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, -1));
    return f(n-1, tar, arr, dp);
}
int countPartitions(vector<int>& arr, int d) {
    // Code here
    int totsum = 0;
    for(auto &it: arr) totsum+=it;
    if(totsum-d < 0 || (totsum - d)%2) return false;
    return findways(arr, (totsum-d)/2);
}