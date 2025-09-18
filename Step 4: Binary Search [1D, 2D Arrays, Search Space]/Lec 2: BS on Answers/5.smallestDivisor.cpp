#include<bits/stdc++.h>
using namespace std;

bool underThreshold(vector<int>& arr, int threshold, int divisor){
    for(int i = 0; i < arr.size(); i++){
        threshold -= ((long long)arr[i]+divisor-1)/divisor;
        if(threshold < 0) return false;
    }
    return true;
}
int optimal(vector<int>& arr, int threshold) {
    int max = arr[0];
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > max) max = arr[i];
    }
    int low = 1;
    int high = max;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(underThreshold(arr, threshold, mid)) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    // Given an array of numbers, return the smallest divisor such that after dividing entire array with that divisor(ceil division), the sum of the array is less than or equal to given threshold.
    vector<int> arr = {1,2,5,9};
    int threshold = 6;

    // Brute Force: O(n*ans) , O(1)
    // Start with 1 as divisor and keep increasing until u find the first divisor that works.
    // To check if a divisor works, I just subtract each ceil(arr[i]/divisor) from threshold, if at any point threshold becomes negative, then that means the sum of the array after division would have been greater and we need to choose a larger divisor to reduce the sum.
    // The function just return true if the sum would have been under threshold or not.

    // Optimal Solution: O(n*log(max)) , O(1)
    // Since we know the range of answers is from 1 to max in the array, also that until a certain point no answers are possible and after that every answer is possible, we use binary search to find that certain point.
    // Nothing new from last problem except we have to start from 1 here and we cant start from min, cuz we are asked for the smallest divisor and a smaller divisor than the one present in array could be possible if threshold is high enough.
    cout<<optimal(arr, threshold);

    std::cout<<"\n\n";
    return 0;
}