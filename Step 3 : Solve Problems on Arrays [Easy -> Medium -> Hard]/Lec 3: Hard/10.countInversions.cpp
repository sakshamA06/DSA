#include<bits/stdc++.h>
using namespace std;

int bf(vector<int> arr){
    int n = arr.size();
    int inversions = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]) inversions++;
        }
    }
    return inversions;
}

int optimal(vector<int>& arr, int start, int end){
    int inversions = 0;
    if(start >= end) return inversions;
    int mid = (start + end) / 2;

    inversions += optimal(arr, 0, mid);
    inversions += optimal(arr, mid+1, end);

    vector<int> temp;
    int left = start;
    int right = mid+1;

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
            inversions += mid - left + 1;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= end){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = start; i <= end; i++){
        arr[i] = temp[i-start];
    }
    return inversions;
}

int main(){
    // Given an array return the number of pairs of inversions.
    // A pair {arr[i], arr[j]} is an inversion if i < j && arr[i] > arr[j]
    vector<int> arr = {5,3,2,4,1}; // 8 inversions

    // Brute Force: O(n^2) , O(1)
    // Generate each pair and check if its an inversion.
    // cout<<bf(arr);

    // Optimal Solution: O(n log n) , O(n)
    // Do merge sort and for the "merging" step in merge sort, if u find an element in left half of current array that is greater than the element at right half, then that means all the remaining elements in the left half can form a pair with the element in right half, so add all these at once.
    cout<<optimal(arr, 0, arr.size()-1);

    std::cout<<"\n\n";
    return 0;
}