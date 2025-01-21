// You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

// Example:

// Input: 
// L = 4, R = 8 
// Output:
// 8 
// Explanation:
// 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8

class Solution {
  public:
    int func1(int n){
        if(n%4==0) return n;
        if(n%4==1) return 1;
        else if(n%4==2) return n+1;
        else if(n%4==3) return 0;
    }
    
    int findXOR(int l, int r) {
        // complete the function here
        return func1(l-1) ^ func1(r);
    }
};