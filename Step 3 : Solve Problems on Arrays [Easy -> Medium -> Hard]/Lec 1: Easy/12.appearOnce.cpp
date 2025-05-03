#include<bits/stdc++.h>

int main(){
    // Given an array of numbers where every number appears twice except one number, find that one number.
    int n = 7;
    int arr[n] = {1, 1, 2, 3, 3, 4, 4};

    // Brute Force: O(n^2) , O(1)
    // Select an element and find its pair in the array and keep repeating for every element, whichever number doesnt have a pair is the desired result.
    int once = 0;
    for(int i = 0; i < n; i++){
        int found = false;
        for(int j = 0; j < n; j++){
            if(i!=j && arr[i] == arr[j]){
                found = true;
                break;
            }
        }
        if(!found){
            once = arr[i];
            break;
        }
    }

    // Optimal Solution: O(n) , O(1)
    // XOR every number, works as missing number problem i.e. every pair of number will resolve to 0 and it will xor to the number appearing once giving the final result as that number.

    // int once = 0;
    // for(int i = 0; i < n; i++){
    //     once ^= arr[i];
    // }
    
    std::cout<<once;

    std::cout<<"\n\n";
    return 0;
}