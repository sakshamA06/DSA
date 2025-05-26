#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int> arr, int key){
    int upper_bound = arr.size();
    int low = 0;
    int high = upper_bound-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == key) return mid;
        else if(arr[mid] > key){
            upper_bound = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return upper_bound;
}

int main(){
    // Given a sorted array and a key, either find the key's index if its present or return the index where it could be inserted without distorting the sorting.
    vector<int> arr = {1,3,5,6};
    int key = 7; // should return 4

    // Opitmal Solution: O(log n) , O(1)
    // Inserting the key at an element smaller than it would disrupt the order, so we have to insert it at the minimum index which is greater than key, so upper bound, and if its equal to key then we have found the element.
    cout<<optimal(arr, key);

    std::cout<<"\n\n";
    return 0;
}