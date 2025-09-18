#include<bits/stdc++.h>
using namespace std;

int bf(vector<int>& arr, int k){
    int missing = 0;
    for(int i = 0; i < arr.size(); i++){
        missing = arr[i] - (i+1);
        if(missing >= k) return arr[i] - (missing-k+1); // or return k+i
    }
    return k + arr.size();
}

int optimal(vector<int>& arr, int k){
    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr[mid] - (mid+1) < k) low = mid+1;
        else high = mid-1;
    }
    return low+k;
}

int main(){
    // Given an array of sorted positive integers, return the kth missing number.
    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    // missing numbers are {1,5,6,8,9,10,12,13,....}, and 5th number here is 9.

    // Brute Force: O(n) , O(1)
    // Traverse the array and keep checking if the current amount of missing numbers has crossed k. Current amount of missing numbers = arr[current] - (current+1)
    // Lets say array was {1,2,3,4,5} originally with nothing missing, now say the array becomes {1,2,3,6,9} then at place of 4, we got 6, meaning 2 numbers are missing which is (6-4). Same for 9, it was supposed to be 5 but (9-5 = 4) numbers are missing so its 9.
    // Now once the number of missing integers cross k, we know the value of kth missing number has to be less than arr[current]. Lets take the above given example, when we reach 11(index 4), we know missing = 11-(4+1) = 6 numbers(1,5,6,8,9,10).
    // So now 6 numbers are missing, and we have to find the 5th one. Notice since till 7 we didnt have enough missing numbers(3 only), any extra missing numbers after that has to be consecutive till current(11). So 6th missing number would be just before 11(i.e. 10), 5th missing just 2 before(i.e. 9), for any k, the kth missing number would be missing-k+1 before 11. So just return arr[i] - (missing-k+1). If we put the value of missing here(arr[i] - (i+1)) we get i+k, so we can return that too.
    // If we dont find any index where total missing number exceeds k, then that means the missing number is more than last integer in array, so we just find that by adding the amount of missing numbers after taking out however many were there till last element. There were arr[last] - (last+1) missing numbers till last. So remaining missing numbers are k-missing = k - (arr[last]-(last+1)) and now we just add this remaining missing numbers to last to get the kth missing number. So arr[last] + k - arr[last] + (last+1) = k+last+1 = k + arr.size()
    // cout<<bf(arr, k);

    // Optimal Solution: O(log n) , O(1)
    // We are finding the same index at which there are more missing numbers than k.
    // After the BS ends, low will point to this index and high will point to the index at which there are less or same missing numbers as k just to the immediate left of low.
    // from arr[low] we can get the kth missing number by arr[low] - (missing-k+1) which after plugging value of missing we get low+k
    // from arr[high] we can get the kth missing number by arr[high] + (k-missing) which is k+high+1, and since high+1 = low, this is just low+k
    cout<<optimal(arr, k);

    std::cout<<"\n\n";
    return 0;
}