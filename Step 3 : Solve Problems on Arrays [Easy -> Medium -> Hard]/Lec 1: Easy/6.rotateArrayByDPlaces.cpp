#include<bits/stdc++.h>

int main(){
    // Given an array of size n, left rotate it by D places
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5}; // for D = 3, left rotate it to {4, 5, 1, 2, 3}
    int D = 3;

    D = D%n; // to handle D larger than n

    // Brute Force 1: O(nD), O(1)
    // Just run the "rotate by one" algo D times

    // for(int j = 0; j < D; j++){
    //     int temp = arr[0];
    //     for(int i = 0; i < n-1; i++){
    //         arr[i] = arr[i+1]; 
    //     }
    //     arr[n-1] = temp;
    // }

    // Brute Force 2: O(2n) , O(n)
    // Create a temp array that is filled starting from D index of arr and after arr is finished, add the starting elements, i traverses circularly in the array then copy the temp array back to original.
    // int temp[n];
    // for(int i = D%n, j = 0; j < n; i = (i+1)%n, j++){
    //     temp[j] = arr[i];
    // }
    // for(int i = 0; i < n; i++){
    //     arr[i] = temp[i];
    // }


    // Better Solution: O(n+D), O(D)
    // Store the elements to send back by rotating in a temp array, like the temp variable for single rotation, then move the remaining elements to start of array and paste the temp array after these elements.

    // int temp[D];
    // for(int i = 0; i < D; i++){ // O(D)
    //     temp[i] = arr[i];
    // }
    // for(int i = D; i < n; i++){ // O(n-D)
    //     arr[i-D] = arr[i];
    // }
    // for(int i = n-D; i < n; i++){ // O(D)
    //     arr[i] = temp[i - (n-D)];
    // }

    // Optimal Solution: O(2n) , O(1)
    // Reverse the sub-array from [0, D), then reverse [D, n), then reverse [0, n)
    // - Reverse the array then reverse these sub arrays to rotate it right D times.
    // Ideally done using functions
    int start = 0, end = D-1;
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    start = D, end = n-1;
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    start = 0, end = n-1;
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }

    for(int i = 0; i < n; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\n\n";
    return 0;
}