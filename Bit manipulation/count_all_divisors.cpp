// Problem statement
// You are given a natural number ‘N’. Find all the divisors of the number ‘N’. Print them in increasing order.

// Example:
// Input: ‘N’ = 10 

// Output: [1, 2, 5, 10]

// 1, 2, 5, and 10 are the only divisors of the number 10.

#include <bits/stdc++.h> 
vector<int> getAllDivisors(int n){
    // Write your code here
    vector<int> divisors;

    // Step 1: Find all divisors up to sqrt(N)
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) { // Check if 'i' is a divisor of 'n'
            divisors.push_back(i); // Add 'i' to the list
            if (i != n / i) { // Avoid duplicate for perfect squares
                divisors.push_back(n / i); // Add the corresponding divisor
            }
        }
    }

    // Step 2: Sort the divisors in ascending order
    sort(divisors.begin(), divisors.end());

    // Step 3: Print the divisors
    return divisors;
}