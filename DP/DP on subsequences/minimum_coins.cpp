// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

class Solution {
    public:
        int f(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
            
            if(ind==0){
                if(target%coins[ind]==0) return target/coins[ind];
                else return 1e9;
            }
            
            if(dp[ind][target] != -1) return dp[ind][target];
            int nottake = 0 + f(ind-1, target, coins, dp);
            int take = INT_MAX;
            if(coins[ind] <= target) take = 1 + f(ind, target-coins[ind], coins, dp);
    
            return dp[ind][target] = min(take, nottake);
        }
        int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();
            vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    
            int ans = f(n-1, amount, coins, dp);
            if(ans >= 1e9)
                return -1;
            return ans;
        }
    };