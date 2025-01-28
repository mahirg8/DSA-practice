// Given an array of N integers and Q queries of indices. For each query indices[i], determine the count of elements in arr that are strictly greater than arr[indices[i]] to its right (after the position indices[i]).

// Examples :

// Input: arr[] = [3, 4, 2, 7, 5, 8, 10, 6], queries = 2, indices[] = [0, 5]
// Output:  [6, 1]
// Explanation: The next greater elements to the right of 3(index 0) are 4,7,5,8,10,6. The next greater elements to the right of 8(index 5) is only 10.

class Solution{
public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int> result(queries, 0);
        
        for(int q=0; q<queries; q++){
            int index  = indices[q];
            int cnt=0;
            
            for(int i=index+1; i<n; i++){
                if(arr[i] > arr[index]){
                    cnt++;
                }
            }
            
            result[q] = cnt;
        }
        
        return result; 
    }

};