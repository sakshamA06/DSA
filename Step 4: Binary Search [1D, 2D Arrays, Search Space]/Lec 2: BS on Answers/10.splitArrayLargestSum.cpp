#include<bits/stdc++.h>
using namespace std;

bool possibleDivision(vector<int> arr, int k, int sum){
    int subarrays = 1;
    int accSum = 0;
    for(int i = 0; i < arr.size(); i++){
        accSum += arr[i];
        if(accSum > sum){
            subarrays++;
            accSum = arr[i];
        }
        if(subarrays > k) return false;
    }
    return true;
}
int optimal(vector<int>& arr, int k) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = low + (high-low)/2;
        if(possibleDivision(arr, k, mid)) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    // Given an array and an integer k, split the array into k non-empty subarrays such that the largest sum of any subarray is minimized. Return this minimized sum.
    vector<int> arr = {7,2,5,10,8};
    int k = 2;

    // Literally the same question as before just changed its form. I just copy pasted the solution to allocatePages and changed the names of variables and function to make it relevant to this problem, and it worked.
    cout<<optimal(arr, k);

    std::cout<<"\n\n";
    return 0;
}