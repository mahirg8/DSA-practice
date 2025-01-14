// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

// Only numbers 1 through 9 are used.
// Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

void help(int i, int k, int sumTillNow, int n, vector<int>&subset, vector<vector<int>> &ans){
        if(k<0) return;
        if(sumTillNow==n){
            if(k==0){
                ans.push_back(subset);
            }
            return;
        }
        if(i==10) return;

        sumTillNow+=i;
        subset.push_back(i);
        help(i+1, k-1, sumTillNow, n, subset, ans);
        sumTillNow-=i;
        subset.pop_back();

        help(i+1, k, sumTillNow, n, subset, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        help(1,k,0,n,subset,ans);
        return ans;
    }