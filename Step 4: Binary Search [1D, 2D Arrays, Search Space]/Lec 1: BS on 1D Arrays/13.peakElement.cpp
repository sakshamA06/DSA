#include<bits/stdc++.h>
using namespace std;

int optimal(vector<int>& arr){
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;
    int low = 1;
    int high = n-2;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;
        if(arr[mid] < arr[mid+1]){ // mid lies in increasing slope
            low = mid+1;
        }
        else high = mid-1;
    }
    return -1;
}

int main(){
    // Given an array of unique neighbouring elements(i.e. arr[i] != arr[i+1] ∀ valid i), find the peak element.
    // An element is peak if its greater than both of its neighbours, we can assume arr[-1] = arr[n] = -∞ so that for the extremes they can be peak just by being greater than thier one neighbour.
    vector<int> arr = {1,20,19,13,12,10,9,7};

    // Optimal Solution: O(log n) , O(1)
    // Making a graph of the elements vs index helps, it is either an increasing slope or decreasing. When it goes from increasing to decreasing, thats where the peak is. So for the condition for eliminating halves, just check if mid is on increasing slope(peak is on right, eliminate left half) or decreasing slope(peak is on left, eliminate right half).
    // Since we have to compare with neighbour elements, its a good idea to start with a search space in which every element has a neigbour, to do this we handle n == 1, and boundary elements separately like in single element problem.
    // For multiple peaks, it doesn't matter, wherever mid lies, it will either be on increasing or decreasing slope, so it will find the local peak.
    // Also it can be the case that mid falls on a dip which means arr[mid] is lesser than both its neighbours, in my conditions this is considered a decreasing slope(the else statement handles it), if u use a else if for decreasing slope then add an else statement for this situation where you can choose to eliminate any half.
    cout<<optimal(arr);

    std::cout<<"\n\n";
    return 0;
}