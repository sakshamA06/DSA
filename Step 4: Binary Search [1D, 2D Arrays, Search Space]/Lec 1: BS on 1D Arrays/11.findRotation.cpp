#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr){
    int ans = arr[0]; // since 1 element in the array is guaranteed.
    int ansi = 0; // index of ans
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[high]){ // Slight optimisation, if the entire current array is sorted then just check with leftmost and done.
            if(arr[low] < ans){
                ansi = low;
                ans = arr[low];
            }
            break;
        }
        if(arr[low] <= arr[mid]){ // Left half is sorted
            if(arr[low] < ans){
                ans = arr[low];
                ansi = low;
            }
            low = mid+1;
        }
        else{ // right half is sorted
            if(arr[mid] < ans){
                ans = arr[mid];
                ansi = mid;
            }
            high = mid-1;
        }
    }
    return ansi;
}

int main(){
    // Given a sorted rotated array, return the minimum.
    vector<int> arr = {7,8,0,1,2,3,4,5,6};

    cout<<optimal(arr);

    std::cout<<"\n\n";
    return 0;
}