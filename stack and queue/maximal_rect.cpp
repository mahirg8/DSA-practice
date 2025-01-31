// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    heights.push_back(0);  // Sentinel value to flush the stack
    int maxArea = 0;
    
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    
    return maxArea;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
    
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int maxRectangle = 0;

    for (int i = 0; i < rows; i++) {
        // Update heights array for histogram
        for (int j = 0; j < cols; j++) {
            heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
        }
        // Find the maximum rectangle in this histogram
        maxRectangle = max(maxRectangle, largestRectangleArea(heights));
    }

    return maxRectangle;
    }
};