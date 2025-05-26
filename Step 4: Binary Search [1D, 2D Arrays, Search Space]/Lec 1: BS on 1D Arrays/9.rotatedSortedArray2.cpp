#include<bits/stdc++.h>
using namespace std;

bool optimal(vector<int> arr, int target){
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(target == arr[mid]) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++; high--;
            continue;
        }
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
    return false;
}

int main(){
    // Given a sorted array rotated some number of times with duplicates, return whether the element exists or not.
    vector<int> arr = {3,3,1,2,3,3,3,3};
    int target = 1;

    // Optimal Solution:
    // TC: O(log n) average, and O(n/2) worst case
    // The only edge case is when arr[low] == arr[mid] == arr[high], this will inhibit us from knowing which half to eliminate. So when we encounter this just shrink the search space by 1 from both sides.
    cout<<optimal(arr, target);

    std::cout<<"\n\n";
    return 0;
}