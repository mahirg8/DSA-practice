// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

 

// Example 1:

// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap; // To store the next greater element for each number in nums2
        stack<int> st; // Monotonic stack to find the next greater elements

        // Traverse nums2 to calculate next greater elements
        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                ngeMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // For remaining elements in the stack, there is no next greater element
        while (!st.empty()) {
            ngeMap[st.top()] = -1;
            st.pop();
        }

        // Prepare the result for nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(ngeMap[num]);
        }

        return result;
    }
};