#include<bits/stdc++.h>

int bf1(std::vector<int> arr, int K){
    // iterate through lengths, reducing it one by one
    for(int i = arr.size(); i > 0; i--){
        // iterate through starting index of different sub arrays of same length
        for(int j = 0; j <= arr.size()-i; j++){    
            int sum = 0;
            // sum the sub array
            for(int k = 0+j; k < i+j; k++){
                sum += arr[k];
            }
            // return early if its hopeless i.e. the required sum is larger than the sum of the array
            if(sum < K) return -1;
            // if sum found then return the length, since i starts from array size and reduces, this will automatically return at the largest length
            if(sum == K) return i;
        }
    }
    // if the sum cannot be obtained from any sub array
    return -1;
}

int bf2(std::vector<int> arr, int K){
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++){
        int sum = 0;
        for(int j = i; j < arr.size(); j++){
            sum += arr[j];
            if(sum == K) maxLen = (maxLen > j-i+1) ? maxLen : j-i+1;
        }
    }
    return maxLen ? maxLen : -1;;
}

int better(std::vector<int> arr, long long K){
    std::map<long long, int> sumMap;
    long long prefixSum = 0;
    int maxlen = 0;
    for(int i = 0; i < arr.size(); i++){
        prefixSum += arr[i]; // stores the total sum of current subarray from 0 to i
        if(prefixSum == K) maxlen = i+1; // if the entire subarray is K then it is the current longest
        long long rem = prefixSum - K; // what the sub array from start should sum upto so that we get a middle subarray which is desired
        if(sumMap.find(rem) != sumMap.end()){
            if(maxlen < i-sumMap[rem]) maxlen = i-sumMap[rem]; // only update maxlen the new 'middle subarray' is larger
        }
        if(sumMap.find(prefixSum) == sumMap.end()) sumMap.emplace(prefixSum, i); // always emplace a new unique entry in sumMap, so that if there are any zeroes, the starting subarray doesnt get larger which will reduce size of middle subarray(which we want to be longest)
    }
    return maxlen;
}

int optimal(std::vector<int> arr, long long K){
    int i = 0;
    int j = 0;
    int sum = arr[0];
    int maxLen = 0;
    while(j < arr.size()){
        while(i <= j && sum > K){
            sum -= arr[i];
            i++;
        }
        if(sum == K) maxLen = maxLen > j-i+1 ? maxLen : j-i+1;
        j++;
        if(j < arr.size()) sum += arr[j];
    }
    return maxLen;
}

int main(){
    // Given an array of positive numbers of size n, find the longest subarray with given sum K. Subarray is contiguous portion of the arra.
    std::vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int K = 3; // return 3 as {1, 1, 1} is longest

    // Brute Force 1: O(n^3) , O(1)
    // Start len with array size, check if its greater than n(no point in continuing if its smaller), if yes then reduce it by 1, check the sum of two subarrays that can be formed with this length, and keep doing it as long as the sum is not met.
    // std::cout<<bf1(arr, K);

    // Brute Force 2: O(n^2) , O(1)
    // Start making subarrays from 0, like 0->0 then 0->1, 0->2 and so on till the end, keep adding subsequent indexes to get the total sum from start to i, and check if the sum is equal to K, if true update when the maxLen is greater than its previous value. After first iteration, change starting point to 1 so that sub arrays are 1->1, 1->2, and so on and keep increasing starting point until u reach the end
    // std::cout<<bf2(arr, K);

    // Better Solution: (Optimal Solution for array with positives and negatives)
    // TC: O(n * log n) for ordered map, O(n*2) for unordered map in worst case(many collisions) and O(n) for unordered map in best and average case
    // SC: O(n) -> n different prefix sum(worst case)

    // The algo:
    // 1. i iterates through the entire array
    // 2. for every i, we set prefix sum = sum of subarray from 0 to i, prefixSum always contains the current sum from 0 to i
    // 3. if this is the K we want, then we update the maxlen to be the size of this subarray
    // 4. otherwise, we check if we have gotten the sum of prefixSum - K previously in the hashmap(variable rem in the code), this would imply there exists a starting subarray which has the sum of prefixSum-K, so the subarray made from after that subarray till current index would have the sum of prefixSum - starting sub array sum = prefixSum - (prefixSum-K) = K, so we have got a middle subarray which sums upto K
    // 5. the length of this middle subarray is current i - wherever the starting subarray ended(stored in hashmap[rem]) => i-sumMap[rem], if this is larger than older len, update it otherwise just move on
    // 6. add the current sum i.e. prefixSum along with the index where the subarray ended to the hashmap(called sumMap)
    // 7. to handle 0s, dont update the hashmap when the prefixSum already exists, as updating would only increase its i(sumMap[rem]), which will decrease len(=i-sumMap[rem]) for any future middle subarray and we want it to be longest
    // std::cout<<better(arr, K);

    // Optimal Solution: O(2n) , O(1)
    // Sliding window: A window has the subarray, enlarge it if the sum is smaller, shrink it if the sum is larger, and store the maximum length found when sum is equal to K. 
    std::cout<<optimal(arr, K);
    

    std::cout<<"\n\n";
    return 0;
}