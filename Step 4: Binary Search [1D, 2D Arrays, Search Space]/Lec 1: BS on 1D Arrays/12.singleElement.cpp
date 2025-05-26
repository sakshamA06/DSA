#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int>& arr){
    int n = arr.size();
    if(n == 1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1;
    int high = arr.size()-2;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid-1] != arr[mid] && arr[mid] != arr[mid+1]) return arr[mid];
        if((mid%2==1 && arr[mid] == arr[mid-1]) || (mid%2==0 && arr[mid] == arr[mid+1])) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    // Given a sorted array with every element appearing exactly twice except one, return the one.
    vector<int> arr = {1,1,2,2,3,3,4,4,10};

    // Optimal Solution: O(log n) , O(1)
    // The main observation here is that before the single element, all duplicates occur at (even, odd) indices, but after the element, it becomes (odd, even).
    // To avoid barrage of conditions to check for boundaries and n == 1, we just handle them first, if n == 1 then the only element present is the answer, and we separately check if the extreme elements are the single element or not.
    // Now our search space is [1, n-2], every element in this search space has an element to both sides of it.
    // The single element wont match with its left or right element, thats how we check if we have found the element.
    // To check which half to eliminate we just check if the duplicates appear like (even, odd) or (odd, even)
    // If the element is in the right half, then that means we are in (even, odd) situation, now if mid is even, then we check to its right for the same element, if mid is odd then we check to its left.
    // If the same element is found then that means we were correct and the element is in right half, otherwise its in left half.
    cout<<optimal(arr);

    std::cout<<"\n\n";
    return 0;
}