#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr, int x){
    int lower_bound = arr.size();
    
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            lower_bound = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    
    return lower_bound;
    // return low; // or you can just return low
}

int main(){
    // Given a sorted array(may or may not be unique) and a number, return the lower bound of the number x.
    // Lower bound is the minimum index such that arr[index] >= number
    // Another way to say it, whats the first element that is greater or equal to than the number, index of that first element is the lower bound of the number.
    vector<int> arr = {2, 3, 5, 8, 15, 19};
    int x = 8; // for x = 6,7,8 lower bound is 3, for x = 5 its 2

    // Brute Force: O(n) , O(1)
    // Traverse from left and if u find any element >= number then that is the lower bound. Basically a linear search.

    // Optimal Solution: O(log n) , O(1)
    // Using Binary Search, if the mid is greater than or equal to the number then this mid is a potential lower bound, so we update lower_bound and look to the left for an even smaller possible lower_bound.
    cout<<optimal(arr, x);
    
    std::cout<<"\n\n";
    return 0;
}