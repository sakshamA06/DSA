#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr){
    int ans = arr[0]; // since 1 element in the array is guaranteed.
    int low = 0, high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[high]){ // Slight optimisation, if the entire current array is sorted then just check with leftmost and done.
            ans = min(ans, arr[low]);
            return ans;
        }
        if(arr[low] <= arr[mid]){ // Left half is sorted
            ans = min(ans, arr[low]);
            low = mid+1;
        }
        else{ // right half is sorted
            ans = min(ans, arr[mid]);
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    // Given a sorted rotated array, return the minimum.
    vector<int> arr = {7,8,0,1,2,3,4,5,6};

    cout<<optimal(arr);

    std::cout<<"\n\n";
    return 0;
}