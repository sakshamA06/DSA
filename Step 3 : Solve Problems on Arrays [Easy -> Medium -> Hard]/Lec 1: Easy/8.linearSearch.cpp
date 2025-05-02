#include<bits/stdc++.h>

int main(){
    // Given an array of size n and key, return the first occurance of key in the array if present or -1 if its absent
    int n = 5;
    int arr[n] = {2, 1, 3, 0, 4};
    int key = 3; // return 2

    // Optimal Solution: O(n) , O(1)
    int ret = -1; // if it was a function then I would have returned this variable
    for(int i = 0; i < n; i++){
        if(arr[i] == key){
            ret = i;
            break;
        }
    }

    std::cout<<"\n\n";
    return 0;
}