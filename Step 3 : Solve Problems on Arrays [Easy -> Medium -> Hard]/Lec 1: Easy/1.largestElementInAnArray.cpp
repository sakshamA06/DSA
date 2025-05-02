#include<bits/stdc++.h>

int main(){
    // Given an array of size n, find the largest element
    int n = 5;
    int arr[n] = {4, 1, 2, 3, 0}; // return 4

    // Brute force: O(n * log n) , O(1)
    //  Sort it then choose the last element

    // Optimal solution: O(n) , O(1)
    int max = arr[0];
    for(int i=0; i<n; i++) if(arr[i] > max) max = arr[i];

    std::cout<<max;

    std::cout<<"\n\n";
    return 0;
}