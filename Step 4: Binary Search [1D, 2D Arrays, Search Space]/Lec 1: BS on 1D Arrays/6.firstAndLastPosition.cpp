#include<bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> arr, int target){
    int fo = -1, lo = -1; // first occurance and last occurance.
    
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            fo = mid;
            high = mid-1; // move the search space left
        }
        else if(arr[mid] > target) high = mid-1;
        else low = mid+1;
    }
    low = 0, high = arr.size()-1; // reset the search space
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            lo = mid;
            low = mid+1; // move the search space right
        }
        else if(arr[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return {fo, lo};
}

int main(){
    // Given a sorted array, find the first and last occurance of a given element.
    vector<int> arr = {5,7,7,8,8,8,10};
    int target = 8;

    // Brute Force: O(n) , O(1)
    // Just do a linear search for the target and keep track of when it starts matching and when it stops

    // Optimal Solution: O(log n) , O(1)
    // Method 1: Using lower and upper bound. This has two edge cases, one when we have gotten a lower/upper bound but its not the target, cuz both have > symbol in the condition to update, and another edge case is the target not found so both will return the index just after the last element(i.e. size of array), if its any of these then set both to -1 otherwise we have our answer.
    int lb = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), target) - arr.begin() -1;
    if(lb == arr.size() || arr[lb] != target) lb = ub = -1;
    // cout<<"{"<<lb<<", "<<ub<<"}";

    // Method 2: Intuitive binary search
    // Just look for first and last occurance with two binary searches, for first u just need to keep moving left if u find the target, and move right for last occurance.
    // You can also separate the functions for first and last occurance and return {-1, -1} right away if u dont find it in fo, might save log n time in some cases but i didnt do that optimisation here.
    cout<<optimal(arr, target)[0]<<", "<<optimal(arr, target)[1];

    std::cout<<"\n\n";
    return 0;
}