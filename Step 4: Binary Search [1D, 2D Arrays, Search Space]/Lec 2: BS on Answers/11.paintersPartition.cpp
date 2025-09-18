#include<bits/stdc++.h>
using namespace std;

bool possibleToPaint(vector<int> arr, int k, int maxArea){
    int painters = 1;
    int accArea = 0;
    for(int i = 0; i < arr.size(); i++){
        accArea += arr[i];
        if(accArea > maxArea){
            painters++;
            accArea = arr[i];
        }
        if(painters > k) return false;
    }
    return true;
}
int optimal(vector<int>& arr, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = low + (high-low)/2;
        if(possibleToPaint(arr, k, mid)) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    // Given an array of board sizes and k painters, allocate the boards to these painters such that they take minimum time to paint all boards, if they take 1 unit time to paint 1 unit area of board. Any painter will only paint coninuous boards. Basically so that the maximum area a painter gets to paint is minimized. Return this minimum time.
    vector<int> arr = {5,10,30,20,15};
    int k = 3;

    // Again the same problem as 9 and 10 just worded differently.
    cout<<optimal(arr, k);

    std::cout<<"\n\n";
    return 0;
}