// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

#include <stack>
#include <climits>

class MinStack {
private:
    std::stack<long long> st; // Use long long for calculations
    long long mini = LLONG_MAX; // Use long long for mini

public:
    MinStack() {
    }

    void push(int val) {
        long long value = val;
        if (st.empty()) {
            mini = value;
            st.push(value);
        } else {
            if (value > mini) {
                st.push(value);
            } else {
                st.push(2 * value - mini); // Push the encoded value
                mini = value;             // Update the minimum
            }
        }
    }

    void pop() {
        if (st.empty()) return;
        long long x = st.top();
        st.pop();
        if (x < mini) {
            mini = 2 * mini - x; // Retrieve the previous minimum
        }
    }

    int top() {
        if (st.empty()) {
            return -1; // Return -1 if the stack is empty
        }
        long long x = st.top();
        return (x < mini) ? mini : x; // Return the decoded top value
    }

    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */