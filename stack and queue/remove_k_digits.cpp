// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
    
    for (char digit : num) {
        while (!st.empty() && k > 0 && st.top() > digit) {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    
    // Remove remaining k digits from the top
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // Construct the result from the stack
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    // Reverse to restore the correct order
    reverse(res.begin(), res.end());

    // Remove leading zeros
    int start = 0;
    while (start < res.size() && res[start] == '0') {
        start++;
    }
    
    res = res.substr(start);
    
    return res.empty() ? "0" : res;
    }
};