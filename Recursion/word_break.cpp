// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    int dp[301];
    int help(int i, string s, set<string> &wordDict){
        if(i==s.size()) return 1;
        string temp;
        if(dp[i]!=-1) return dp[i];
        for(int j=i; j<s.size(); j++){
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(help(j+1, s, wordDict)) return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        memset(dp, -1, sizeof dp);
        for(auto a: wordDict)st.insert(a);
        return help(0,s,st);
    }
};