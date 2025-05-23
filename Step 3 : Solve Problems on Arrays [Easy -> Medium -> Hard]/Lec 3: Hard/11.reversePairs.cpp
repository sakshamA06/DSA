#include<bits/stdc++.h>
using namespace std;

int bf(vector<int> arr){
    int n = arr.size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > 2 * arr[j]) cnt++;
        }
    }
    return cnt;
}

int countPairs(vector<int>& arr, int start, int mid, int end){
    int cnt = 0;
    int left = start;
    int right = mid+1;
    while(left <= mid && right <= end){
        if(arr[left] > 2 * arr[right]){
            cnt += mid - left + 1;
            right++;
        }
        else{
            left++;
        }
    }
    return cnt;
}

int optimal(vector<int>& arr, int start, int end){
    int inversions = 0;
    if(start >= end) return inversions;
    int mid = (start + end) / 2;

    inversions += optimal(arr, 0, mid);
    inversions += optimal(arr, mid+1, end);
    inversions += countPairs(arr, start, mid, end);

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
    // Given an array return the reverse pairs.
    // A pair {arr[i], arr[j]} is a reverse pair if i < j && arr[i] > 2 * arr[j]
    vector<int> arr = {1,3,2,3,1}; // 2
    // vector<int> arr = {2,4,3,5,1}; // 3
    // vector<int> arr = {5,3,2,4,1}; // 8

    // Brute Force: O(n^2) , O(1)
    // Generate each pair and check if its a reverse pair.
    // cout<<bf(arr);

    // Optimal Solution: O(n log n) , O(n)
    // Do merge sort and before merging, count the number of pairs.
    // We can count it like this in inversions problem too but since the conditions match for both inversion and merge sort, we accomodated it inside.
    // Before merging the two halves of the split array are sorted due to how merge sort works.
    cout<<optimal(arr, 0, arr.size()-1);

    std::cout<<"\n\n";
    return 0;
}