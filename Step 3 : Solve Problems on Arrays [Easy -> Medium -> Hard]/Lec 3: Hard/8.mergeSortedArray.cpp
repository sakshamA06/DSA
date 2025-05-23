#include<bits/stdc++.h>
using namespace std;

void optimal(vector<int>& arr1, int m, vector<int>& arr2, int n){
    int p1 = m-1;
    int p2 = n-1;
    int largest = m+n-1;
    while(p2>=0){
        if(p1>=0 && arr1[p1] >= arr2[p2]){
            arr1[largest] = arr1[p1];
            p1--;
        }
        else{
            arr1[largest] = arr2[p2];
            p2--;
        }
        largest--;
    }
}

int main(){
    // Given two sorted arrays of length m and n, merge them into a single sorted array inside the first array(actual size is m+n to accomodate). After first m elements first array contains only 0s.
    // The question striver did in video vs linked in leetcode are different, this is the solution to leetcode one.
    vector<int> arr1 = {1,2,3,4,0,0,0};
    vector<int> arr2 = {2,5,6};
    int n = arr2.size();
    int m = arr1.size() - n; // arr1.size() = m+n, so int m = (m+n) - n
    
    // Brute Force 1: O(n) + O((m+n)log(m+n)) , O(1)
    // Fill the first array with second array's elements from index m, and sort it.
    // Brute Force 2: O(m+n) + O(m+n) , O(m+n)
    // Create a separate array, use two pointer merge method like used in merge sort to populate the third array, and copy it back to first array.

    // Optimal Solution:
    // The same two pointer approach:
    // Since we cant merge starting from index 0 as it will over write the current elements, we start from back, filling the largest element first and traversing right to left.
    // One pointer at last element of arr1(m-1), another at last element of arr2(n-1), and one more pointer at last position of arr1(m+n-1) which will indicate where to put the next largest number.
    // Compare last elements of arr1 and arr2, greater one gets inserted at last, and move the pointer for that array to left and keep going until arr2 is exhausted, after that the rest of arr1 will be sorted as it was sorted to begin with.
    // We also need to address the edge case where m=0, if arr1 has no elements then we just insert arr2 elements in it, but p1 = -1 so we only check if arr1[p1] > arr2[p2] if p1 is not -1(or >=0)
    optimal(arr1, m, arr2, n);

    for(auto it: arr1) cout<<it<<" ";

    std::cout<<"\n\n";
    return 0;
}