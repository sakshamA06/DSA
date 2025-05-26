#include<bits/stdc++.h>
using namespace std;

int first_occurance(vector<int> arr, int target){
    int fo = -1;
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
    return fo;
}

int last_occurance(vector<int> arr, int target){
    int lo = -1;
    int low = 0, high = arr.size()-1; // reset the search space
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target){
            lo = mid;
            low = mid+1; // move the search space right
        }
        else if(arr[mid] > target) high = mid-1;
        else low = mid+1;
    }
    return lo;
}

int optimal(vector<int> arr, int target){
    int f = first_occurance(arr, target);
    if (f == -1) return 0;
    int l = last_occurance(arr, target);
    return l-f+1;
}

int main(){
    // Given a sorted array, count the number of occurances of an element.
    vector<int> arr = {2,3,4,4,4,5,7,7,8,10};
    int target = 4;

    // Optimal Solution: O(log n) , O(1)
    // Just calculate from first and last occurance.
    cout<<optimal(arr, target);

    std::cout<<"\n\n";
    return 0;
}