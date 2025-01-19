// Problem statement
// You are given two integers, ‘dividend’ and ‘divisor’.



// You are required to divide the integers without using multiplication, division, and modular operators.



// Your task is to return the quotient after dividing ‘dividend’ by ‘divisor’.



// Note :

// In cases where the dividend is not perfectly divisible by the divisor, you are required to return the integer value of the quotient which is closer to zero.

// For example - If the answer is '8.34', we return the integer part, i.e., '8'. Also, If the answer is '-2.67', we return the integer part, i.e., '-2'.

// Assume we're dealing with a system that can only store integers in the 32-bit signed integer range: [2^31, 2^31-1]. If the quotient is higher than 2^31 - 1, return 2^31 - 1; if it is less than -2^31, return -2^31. 

#include <bits/stdc++.h>
int divideTwoInteger(int dividend, int divisor) {
	// Write your code here.
	 if(dividend==divisor) return 1;
        bool sign = true;
        if(dividend >= 0 && divisor  < 0) sign = false;
        else if(dividend <= 0 && divisor > 0) sign = false;

        long n = abs(dividend);
        long d = abs(divisor);
        long q = 0;
        while(n>=d){
            int cnt=0;
            while(n >= (d<<(cnt+1))){
                cnt+=1;
            }
            q += 1<<cnt;
            n -= (d<<cnt);
        }
        if(q == (1<<31) && sign){
            return INT_MAX;
        }
        if(q == (1<<31) && !sign){
            return INT_MIN;
        }
        return sign ? q : -q;
} 
