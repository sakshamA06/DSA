#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr, int x){
    int upper_bound = arr.size();
    
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > x){
            high = mid-1;
            upper_bound = mid;
        }
        else{
            low = mid+1;
        }
    }
    return upper_bound;
    // return low; // or you can just return low
}

int main(){
    // Given a sorted array(may or may not be unique) and a number, return the upper bound of the number x.
    // Upper bound is the minimum index such that arr[index] > number
    vector<int> arr = {2, 3, 5, 8, 15, 17};
    int x = 15; // for x = 15,16 upper bound is 5, for x = 14 its 4

    // Brute Force: O(n) , O(1)
    // Traverse from left and if u find any element > number then that is the upper bound. Basically a linear search.

    // Optimal Solution: O(log n) , O(1)
    // Using Binary Search, if the mid is greater than the number then this mid is a potential upper bound, so we update upper_bound and look to the left for an even smaller possible upper_bound.
    cout<<optimal(arr, x);
    

    std::cout<<"\n\n";
    return 0;
}