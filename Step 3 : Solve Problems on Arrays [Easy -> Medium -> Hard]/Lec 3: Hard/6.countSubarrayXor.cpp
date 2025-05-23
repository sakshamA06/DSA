#include<bits/stdc++.h>
using namespace std;

int bf(vector<int> arr, int k){
    int count  = 0;
    for(int i = 0; i < arr.size(); i++){
        int xr = 0;
        for(int j = i; j < arr.size(); j++){
            xr ^= arr[j];
            if (xr == k) count++;
        }
    }
    return count;
}

int optimal(vector<int> arr, int k){
    int count = 0;
    int pfixXor = 0;
    map<int, int> mpp;
    mpp.emplace(0, 1);
    for(int i = 0; i < arr.size(); i++){
        pfixXor ^= arr[i];
        count += mpp[pfixXor ^ k];
        mpp[pfixXor]++;
    }
    return count;
}

int main(){
    // Given an array, count number of subarrays with xor equal to given k.
    vector<int> arr = {4,2,2,6,4};
    int k = 6;

    // Brute Force: O(n^2) , O(1)
    // Generate all subarrays and check their xor
    // cout<<bf(arr,k);

    // Optimal Solution: O(n) , O(n)
    // TC is same for any map time complexity analysis.
    // Same type of stuff as the sum problem.
    // in sum problem we did pfixSum = (pfixSum-k) - k, pfixSum was the sum till current iteration, pfixSum-k were the keys in hashmap, k was the target
    // for xor we can derive a similar formula:
    // pfixXor = x ^ k, where pfixXor is xor till current iteration, x is the xor stored in hashmap and k is the target
    // Eg - 4,2,2,6,4
    // lets say current i is at 4, so arr[i] = 6, and target is 6
    // so x would be 4 and k would be 2^2^6, we need to check if x was in the hash(which it would be), so our goal is to check whether x is present or not in hashmap
    // pfixXor = x ^ k
    // pfixXor ^ k = x ^ k ^ k (xor with k both side)
    // pfixXor ^ k = x
    // so just check if pfixXor^k is present in hashmap, if yes then its frequency is the number of subarrays obtainable with xor = k
    cout<<optimal(arr,k);

    std::cout<<"\n\n";
    return 0;
}