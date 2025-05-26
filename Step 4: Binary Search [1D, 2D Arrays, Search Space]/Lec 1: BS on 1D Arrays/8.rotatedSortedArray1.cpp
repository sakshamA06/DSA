#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr, int target){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(target == arr[mid]) return mid;
        if(arr[low] <= arr[mid]){ // Left half is sorted
            if(arr[low] <= target && target <= arr[mid]){
                high = mid-1;
            }
            else low = mid+1;
        }
        else{ // right half is sorted
            if(arr[mid] < target && target <= arr[high]){
                low = mid+1;
            }
            else high = mid-1;
        }
    }
    return -1;
}

int main(){
    // Given a sorted array rotated some number of times, search for the given element.
    // vector<int> arr = {4,5,6,7,0,1,2};
    // int target = 2;
    vector<int> arr = {3,1};
    int target = 1;

    // Brute Force: O(n) , O(1)
    // Linear search

    // Optimal Solution: O(log n) , O(1)
    // Low mid and high can overlap each other at any time, so we are not using strict inequalities in conditions.
    cout<<optimal(arr, target);

    std::cout<<"\n\n";
    return 0;
}