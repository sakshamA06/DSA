#include<bits/stdc++.h>
using namespace std;

vector<int> bf(vector<int>& arr, int target) {
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size(); j++){
            if(arr[i] + arr[j] == target) return vector<int> {i, j};
            // return "YES"; for variety 1
        }
    }
    return vector<int> {};
    // return "NO"; for variety 1
}

vector<int> better(vector<int>& arr, int target) {
    map<int, int> mpp;
    for(int i = 0; i < arr.size(); i++){
        if(mpp.find(target-arr[i]) != mpp.end()) return vector<int> {mpp[target-arr[i]], i};
        // return "YES"; for variety 1
        mpp[arr[i]] = i;
    }
    return vector<int> {};
    // return "NO"; for variety 1
}

// Part of the optimal solution
void quickSort(vector<int> arr, int low, int high)
{
	if (low>=high) return;
	int pivot = low;
	int i = low;
	int j = high;
	while(i<j)
	{
		while(arr[i] <= arr[pivot] && i<high) i++;
		while(arr[j] > arr[pivot] && j>low) j--;
		if(i<j) swap(arr[i], arr[j]);
	}
	swap(arr[j], arr[pivot]);
	quickSort(arr, low, j-1);
	quickSort(arr, j+1, high);
}

string optimal(vector<int> arr, int target) {
    // Sorting using quicksort -> O(n log n) , O(1)
    quickSort(arr, 0, arr.size()-1);

    int left = 0;
    int right = arr.size()-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target) return "YES";
        else if(sum < target) left++;
        else right--;
    }
    return "NO";
}

int main(){
    // Given an array find whether two numbers in the array add up to given target(variety 1) or return their indices(variety 2)
    vector<int> arr = {2, 6, 5, 8, 11};
    int k = 14;

    // Brute Force: O(n^2) , O(1)
    // Pick an element and loop through the entire array to find out if its compliment exists, if not then pick the next and so on, we can optimise this a little by only looking for the elements after the currently picked element since we have already checked it with any elements behind it in previous iterations(in the loop of picking element).
    // vector<int> result = bf(arr, k);

    // Better Solution: O(n * log n) , O(n) -> Optimal for variety 2
    // Same time complexity analysis as done for any map. Space complexity is O(n) due to the map.
    // Hash the array in a hash map, while checking if the current element has any compliment in the hash array.
    // vector<int> result = better(arr, k);

    // for(int i = 0; i < 2; i++){
    //     cout<<result[i]<<" ";
    // }

    // Optimal Solution: O(n log n) + O(n) , O(n) if considering the distortion of array, otherwise O(1) 
    // Two pointer approach: Sort the array, and keep two pointers at start and end.
    // Add the elements and if its smaller than target, move the left pointer forward(increase the sum), and move the right pointer left if the sum is greater than target. Stop when the sum == target.
    // This is optimal only for variety 1.
    // If you want to return indices then we have to keep the array in some other data structure where element is bound to its index, so that after sorting the indices are preserved.
    string result = optimal(arr, k);
    cout<<result;


    

    std::cout<<"\n\n";
    return 0;
}