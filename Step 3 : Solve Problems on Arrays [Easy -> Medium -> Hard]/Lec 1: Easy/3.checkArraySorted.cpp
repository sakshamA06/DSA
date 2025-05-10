#include<bits/stdc++.h>

int main(){
    // Given an array of size n, check if its sorted.
    int n = 5;
    int arr[n] = {9, 10, 5, 4, 1, 2, 3, 4}; // return false

    // Optimal Solution
    // Time Complexity = O(n)
    // Space Complexity = O(1)
    bool sorted = true;
    for(int i = 0; i < n-1; i++){
        if(arr[i] > arr[i+1]) sorted = false;
    }
    std::cout<<sorted;

    std::cout<<"\n\n";
    return 0;
}