#include<bits/stdc++.h>

int main(){
    // Given an array of size n, left rotate it by one place
    int n = 5;
    int arr[n] = {1, 2, 3, 4, 5}; // left rotate it to {2, 3, 4, 5, 1}

    // Optimal Solution: O(n), O(1)
    // Just store first element, shift everything left, and update it to last, like swapping.
    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i]; 
    }
    arr[n-1] = temp;

    // Right rotate
    // int temp = arr[n-1];
    // for(int i = n-1; i > 0; i--){
    //     arr[i] = arr[i-1]; 
    // }
    // arr[0] = temp;

    for(int i = 0; i < n; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\n\n";
    return 0;
}