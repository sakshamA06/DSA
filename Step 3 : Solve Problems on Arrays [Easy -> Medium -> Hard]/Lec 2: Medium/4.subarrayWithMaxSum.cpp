#include<bits/stdc++.h>

int bfBetter(std::vector<int> arr){ // part 1
// std::vector<int> bfBetter(std::vector<int> arr){ // part 2
    // int start = -1, end = -1; // part 2
    int n = arr.size();
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0; // better solution
        for(int j = i; j < n; j++){
            // <-- bf solution part start
            // int sum = 0;
            // for(int k = i; k <= j; k++){
            //     sum += arr[k];
            // }
            // bf solution part end -->
            sum += arr[j]; // better solution(instead of the above part)

            if(sum > maxSum){
                maxSum = sum;
                // start = i; // part 2
                // end = j; // part 2
            }
        }
    }
    return maxSum; // part 1
    // start and end indices contain the subarray
    // return std::vector<int> {start, end}; // part 2
}

// int optimal(std::vector<int> arr){ // part 1
std::vector<int> optimal(std::vector<int> arr){ // part 2
    int start = -1, end = -1, substart; // part 2
    int maxSum = INT_MIN;
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        if(sum == 0) substart = i; // stores whenever a new subarray starts
        sum += arr[i];
        if(sum > maxSum){
            maxSum = sum;
            start = substart; // only update when the subarray is actually better than the previous one
            end = i;
        }
        if(sum < 0){
            sum = 0;
        }
    }
    // return maxSum; // part 1
    return std::vector<int> {start, end}; // part 2
}

int main(){
    // Given an array, find the maximum sum possible from its subarray.
    // Second part is to return the subarray as well(start and end index)
    std::vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    // std::vector<int> arr = {-2, -3, -4, -1, -2, -1, -5, -3};
    // std::vector<int> arr = {};

    // Brute Force:
    // Try out every subarray, add them, and update the max sum accordingly.
    // Better Solution:
    // Instead of re-adding the entire subarray each time, add only the newest element included in the new subarray as the sum will only update due to that element
    // std::cout<<bfBetter(arr); // part 1
    // std::cout<<"{"<<bfBetter(arr)[0]<<", "<<bfBetter(arr)[1]<<"}"; // part 2
    
    // Optimal Solution: O(n) , O(1)
    // Kadane's algo
    // Add the first element to sum, and update maxSum to sum if sum is greater than it.
    // Reset sum to 0 if sum < 0 because carrying over a negative value won't increase the sum regardless of what the next element is.
    // Don't reset if sum > 0.
    // Add next element to sum and repeat the same steps.
    // std::cout<<optimal(arr);
    std::cout<<"{"<<optimal(arr)[0]<<", "<<optimal(arr)[1]<<"}"; // part 2

    std::cout<<"\n\n";
    return 0;
}