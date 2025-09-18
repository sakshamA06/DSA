#include<bits/stdc++.h>

void nextPermutation(std::vector<int>& arr) {
    int n = arr.size();
    int dip = -1;
    for(int i = n-1; i > 0; i--){
        if(arr[i] > arr[i-1]){
            dip = i-1;
            break;
        }
    }
    if(dip == -1){
        reverse(arr.begin(), arr.end());
        return;
    }
    for(int i = n-1; i > dip; i--){
        if(arr[i] > arr[dip]){
            std::swap(arr[i], arr[dip]);
            break;
        }
    }
    reverse(arr.begin() + dip + 1, arr.end());
}

int main(){
    // Given an array, find the next permutation(lexicographically) in a cyclic order. Elements may repeat.
    // Eg- 1,2,3 -> 1,3,2 ; 3,2,1 -> 1,2,3
    std::vector<int> arr = {4, 3, 2, 1};

    // Brute Force: O(n! * n) , O(n!)
    // Generate all possible permutations in order. {O(n!)}
    // Linear search the given array. {O(n)}
    // Return the next array. If the given array is last, return the first.
    // This is extremely inefficient, TC and SC is very high, so won't implement.

    // Optimal Solution: O(n), O(1)
    // The next permutation of descending array is its reverse or sorted version(both are equal)
    // Find from last, till where is a descending subarray, we name it dip where the first smaller element than the next is found such that arr[dip+1] to arr[n-1] is descending.
    // Swap arr[dip] with the next largest element in the descending portion, we can easily find this element by starting to look from last and picking the first element that is greater than arr[dip]. Since all the elements to the right of it would be smaller than arr[dip] and all the element to the left would only be more larger.
    // Now sort the portion after dip, instead of sorting in O(n log n), we can also just reverse this portion since it will remain in descending order even after swapping.
    // The resultant array is the next permutation.
    nextPermutation(arr);

    for(auto it:arr){
        std::cout<<it<<" ";
    }

    std::cout<<"\n\n";
    return 0;
}