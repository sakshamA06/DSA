#include<bits/stdc++.h>

int main(){
    // Given an array of size n, find the second largest element
    int n = 5;
    int arr[n] = {9, 10, 5, 4, 1, 2, 3, 4}; // return 9

    // Brute force: O(n * log n) , O(1)
    // Sort the array, and traverse back from last element, until u find an element not equal to largest element(i.e. last element)
    
    // Better sol: O(2n) , O(1)
    // First pass: Find the largest number and store it in max
    // Second pass: Traverse the array again and find the largest number, but dont update this variable if the element is equal to max

    // int max = arr[0];
    // for(int i = 0; i < n; i++){
        // if(arr[i] > max) max = arr[i];
    // }
    // int secondMax = INT_MIN; // dont do secondMax = arr[0] cuz first element might be the largest
    // for(int i = 0; i < n; i++){
    //     if(arr[i] > secondMax && arr[i] != max) secondMax = arr[i]; 
    // }
    
    // Optimal Solution: O(n) , O(1)
    // Do second largest = largest if the largest is updated(meaning a new larger element is found the hence the earlier one is second largest now)
    
    int max = arr[0];
    int secondMax = INT_MIN; // dont do secondMax = arr[0] cuz first element might be the largest
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            secondMax = max;
            max = arr[i];
        }
        else if(arr[i] < max && arr[i] > secondMax) secondMax = arr[i];
    }

    std::cout<<secondMax;


    std::cout<<"\n\n";
    return 0;
}