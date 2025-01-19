// Given a positive integer n, write a function that returns the number of 
// set bits
//  in its binary representation (also known as the Hamming weight).

 

// Example 1:

// Input: n = 11

// Output: 3

// Explanation:

// The input binary string 1011 has a total of three set bits.

class Solution {
public:
    int hammingWeight(int n) {
        // Your logic here
        int cnt=0;
        while(n>1){
            cnt += n&1;
            n = n >> 1;
        }
        if(n==1) cnt+=1;
        return cnt;
    }
};
