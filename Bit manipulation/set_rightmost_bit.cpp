// Problem statement
// The problem is to find the rightmost bit of a non-negative number 'N' that is currently unset (i.e., has a value of 0) in its binary representation and set it to 1.



// Return the number after setting the rightmost unset bit of 'N'. If there are no unset bits in N's binary representation, then the number should remain unchanged.



// Example:
// N = 5
// Output: 7
// Explanation: The binary representation of 5 is 101. After setting the rightmost unset bit it becomes 111 which is 7.
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 10
// Sample Output 1:
// 11

int setBits(int N){
    // Write your code here.
    // Check if all bits in N are already set
    if ((N & (N + 1)) == 0) {
        return N; // No unset bits; return the number as is
    }
    // Find the rightmost unset bit and set it
    int mask = ~N & (N + 1);
    return N | mask;
}