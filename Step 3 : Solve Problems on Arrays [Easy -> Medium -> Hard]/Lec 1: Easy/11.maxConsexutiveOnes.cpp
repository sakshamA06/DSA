#include<bits/stdc++.h>

int main(){
    // Given an array of 0s and 1s, return the maximum consecutive occurance of 1s
    int n = 9;
    int arr[n] = {1, 1, 0, 1, 1, 1, 0, 0, 1}; // return 3
    
    // Optimal Solution: O(n) , O(1)
    // Keep increasing count as long as you don't encounter 0, when u do, check if the count(length of current sequence of 1s) is greater than largest length encountered yet, if yes then update it. Finally reset count to 0 for whenever the next sequence of 1s come up.
    
    int maxcount = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            if(count > maxcount) maxcount = count;
            count = 0;
        }
        else count++;
    }

    std::cout<<maxcount;

    std::cout<<"\n\n";
    return 0;
}