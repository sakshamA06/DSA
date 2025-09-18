#include<bits/stdc++.h>
using namespace std;

long long optimal(vector<int>& arr){
    int n = arr.size();
    long long prefix = 1;
    long long suffix = 1;
    long long maximum = 0;
    for(int i = 0; i < n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;



        
        prefix *= (long long)arr[i];
        suffix *= (long long)arr[n-i-1];
        maximum = max(maximum, max(prefix, suffix));
    }
    return maximum;
}

int main(){
    // Given an array of integers, find the largest product a subarray can have.
    vector<int> arr = {2,-1,3,0,5,2,-4,1,3,-1,7};

    // Brute Force: O(n^2) , O(1)
    // Generate all subarrays, find their product, keep track of maximum.
    // Three loops would result in O(n^3) TC, just optimise the third loop to get current TC.

    // Optimal Solution: O(n) , O(1)
    // When there is a zero, that just marks the split of the array into two smaller arrays, a maximum product subarray can't contain 0, so all the max possible subarrays must be those beside the small arrays formed between 0s.
    // From here on, array can mean the entire array if no 0, or the split arrays if there are 0s
    // For even -ves, the entire arrays is max product.
    // For odd -ves, the max is either taking the longest subarray u can leaving leftmost -ve or rightmost -ve, leaving one -ve would make the product positive since there were odd -ves.
    cout<<optimal(arr);


    std::cout<<"\n\n";
    return 0;
}