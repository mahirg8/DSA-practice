// Given a number N. Find its unique prime factors in increasing order.
 

// Example 1:

// Input: N = 100
// Output: 2 5
// Explanation: 2 and 5 are the unique prime
// factors of 100.

class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int> vec;
	    for(int i=2; i<=sqrt(N); i++)
	    {
	        if(N%i==0){
	            vec.push_back(i);
	            while(N%i == 0)
	            {
	                N/=i;
	            }
	        }
	    }
	    if(N!=1)vec.push_back(N);
	    return vec;
	}
};