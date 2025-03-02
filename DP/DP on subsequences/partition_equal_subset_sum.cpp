// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

class Solution {
    public:
        bool f(int ind, int k, int n, vector<int>& nums, vector<vector<int>>& dp){
            vector<bool> prev(k+1, 0), cur(k+1, 0);
            prev[0] = cur[0] = true;
            if(nums[0] <= k) prev[nums[0]] = true;
            for(int ind=1; ind<n; ind++){
                for(int target=1; target<=k; target++){
                    bool nottake = prev[target];
                    bool take = false;
                    if(nums[ind] <= target) take = prev[target-nums[ind]];
                    cur[target] = take | nottake;
                }
                prev = cur;
            }
            return prev[k];
        }
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
    
            int sum = 0;
            for(int i=0; i<n; i++) sum+=nums[i];
            if(sum%2) return false;
            int target = sum/2;
            vector<vector<int>> dp(n, vector<int>(target+1, -1));
            return f(n, target, n, nums, dp);
        }
    };