#include<bits/stdc++.h>
using namespace std;

int bsi(vector<int> arr, int key){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(key < arr[mid]) high = mid-1;
        else if(key > arr[mid]) low = mid+1;
        else return mid;
    }
    return -1;
}

int bsr(vector<int>& arr, int key, int low, int high){
    if(low > high) return -1;
    int mid = low + (high-low)/2;

    if(key == arr[mid]) return mid;
    else if(key < arr[mid]) return bsr(arr, key, low, mid-1);
    else return bsr(arr, key, mid+1, high);
}

int main(){
    // Given a sorted array, do binary search iteratively and recursively on it.
    vector<int> arr = {2, 3, 6, 7, 9, 10, 11, 12, 17, 18};
    int key = 9;

    // Theory: O(log n) , O(1)
    // TC is log base 2, since we half at every step.
    // Will be using mathematical set notation for this explanation.
    // First the search space is entire array, i.e. [0, n) or more preferably written as [0, n-1]
    // The comparison is done with the middle element, its the 'i' of linear search, if the key is lesser than this mid element, then key is in left half and vice versa.
    // If at any point the key is equal to mid's element, we have found it and we return mid.
    // Now to shrink the search space to left half, remembering that we have to write it with both ends inclusive, the search space has to become [0, mid-1]. As the key was less than mid, it cant be mid and must be before mid.
    // To shrink it the other way, it has to become [mid+1, n-1]. Same reasoning, key cant be mid, has to be in the search space after it.
    // Now low denotes the lower bound of search space and high denotes the higher bound, both inclusive.
    // If the key doesn't exist, eventually high > low at which point the search space has been exhausted.
    // Keeping this things in mind should make implementing a binary search easy.
    // One more thing, to prevent integer overflow, you can take int mid = low + (high-low)/2, same thing as (low+high)/2, but if both low and high are big integers, their sum can overflow int, but the former formula only has a subtraction, and we are adding to low however much mid is away from low.

    // Iteratively:
    // Just loop until high > low, and do the steps said above.
    cout<<bsi(arr, key);

    // Recursively:
    // Any deeply nested recursive instance of the function which finds the key will return, and its caller will return that, and so on, the through a return chain we will get the index in original function which ofcourse will return it.
    // cout<<bsr(arr, key, 0, arr.size()-1);

    std::cout<<"\n\n";
    return 0;
}