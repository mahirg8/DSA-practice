string postToInfix(string exp) {
    // Write your code here.
    stack<string> st; // Stack to hold intermediate infix expressions

        for (char ch : exp) {
            // If the character is an operand, push it onto the stack
            if (isalnum(ch)) {
                st.push(string(1, ch));
            } else {
                // If the character is an operator, pop two operands from the stack
                string operand2 = st.top();
                st.pop();
                string operand1 = st.top();
                st.pop();

                // Form the infix expression and push it back onto the stack
                string infix = "(" + operand1 + ch + operand2 + ")";
                st.push(infix);
            }
        }

        // The final infix expression is the only element left in the stack
        return st.top();
}