// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            int prev = nums[0];
            int prev2 = 0;
            for(int i=1; i<n; i++){
                int take = nums[i];
                if(i>1) take+=prev2;
                int nottake = 0 + prev;
    
                int cur = max(take, nottake);
                prev2 = prev;
                prev = cur;
            }
            return prev;
        }
    };