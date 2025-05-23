#include<bits/stdc++.h>

int bf(std::vector<int>& arr, int k){
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        int sum = 0;
        for(int j = i; j < arr.size(); j++){
            sum += arr[j];
            if(sum == k) count++;
        }
    }
    return count;
}

int optimal(std::vector<int>& arr, int k){
    int pfixSum = 0;
    int count = 0;
    std::unordered_map<int, int> mpp;
    // mpp[0] = 1; // either this or
    for(int i = 0; i < arr.size(); i++){
        pfixSum += arr[i];
        if(pfixSum == k) count++; // this
        count += mpp[pfixSum-k];
        mpp[pfixSum]++;
    }
    return count;
}

int main(){
    // Given an array of integers, find the number of subarrays that add upto given sum K.
    std::vector<int> arr = {1,1,1};

    // Brute Force: O(n^2) , O(1)
    // Generate all subarrays and count the number of them that have the sum K.
    // Now there are two ways to get sum, one is pure bf, iterate through each subarray to find its sum, other is more optimised, while generating subarrays add the new element to the sum, no need to re-calculate the sum of entire subarray except the new element.
    // First is brute force of striver(O(n^3)) and second is his better solution.
    // std::cout<<bf(arr, 2);

    // Optimal Solution: O(n) , O(n)
    // Same as number 13 in easy (and this is number 13 in medium lol). Using prefix sum.
    // pfixSum for any i stores sum of subarray [0,i], pfixSum-k is the value that some subarray [0,l] (0<=l<i) sum is equal to such that [l,i] is the subarray with sum of k
    // The key value pair map here is pfixSum and its frequency, since there can be multiple subarrays with the same sum which would mean leaving them from a larger subarray would result in same sum which we have to count differently.
    // arr = {3, -3, 1, 1}, for k=2, either take subarray [0,3] or [2,3].
    // In the map (0, 1) is necessary bcuz when pfixSum-k == 0 for any i, we might not have a pfixSum of 0 before but we still have to count this sub array bcuz this subarray is [0,i]
    // Or we can just do count++ whenever pfixSum-k==0 or pfixSum == k, this was done in longest subarray with sum K problem so we didnt add (0, 1)
    std::cout<<optimal(arr, 3);




    std::cout<<"\n\n";
    return 0;
}