#include<bits/stdc++.h>
using namespace std;

bool underCapacity(vector<int>& weights, int days, int capacity){
    int perDayLoad = 0;
    int day = 1;
    for(int i = 0; i < weights.size(); i++){
        if(perDayLoad + weights[i] > capacity){
            day++;
            perDayLoad = weights[i];
        }
        else perDayLoad += weights[i];
        if(day > days) return false;
    }
    return true;
}
int optimal(vector<int>& weights, int days) {
    int max = weights[0];
    int sum = weights[0];
    for(int i = 1; i < weights.size(); i++){
        sum += weights[i];
        if(weights[i] > max) max = weights[i];
    }
    int low = max;
    int high = sum;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(underCapacity(weights, days, mid)) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    // Given an array of weights of different items to be loaded in a ship, return the minimum capacity of the ship to carry every item across within given days if the ship only travels once per day and you can only load items from left to right, and not randomly anyone.
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    // Brute Force: O(n + n*(ans-max)) , O(1)
    // TC: n for finding max and sum, (ans-max) for iterations from max to ans and each iteration checks for underCapacity(~O(n)) so n*(ans-max)
    // Minimum capacity can be max(weights) since if capacity was 9 it would never be able to carry the item with 10 weight. Maximum capacity can be infinite ofc but practically anything after the sum of weights is useless, if capacity was 55, the ship could take every item in one day, no point in capacity being higher than 55.
    // So iterate from max(weights) to sum(weights), and check each capacity, if its possible then return that as it will be minimum.(returning the first possible capacity)
    // To check if the capacity is possible, we iterate through weights, and keep track of what day it is that we can carry these items, if adding the current item to today's payload exceeds the capacity, we conclude that the ship sailed with those many items today, and increment the day to make it tomorrow, if it doesnt exceed the capacity then we just keep adding it to current day's payload.
    // Now if we have crossed the limit of days given, then check the next capacity in the next iteration.

    // Optimal Solution: O(n + n*log(sum-max)) , O(1)
    // Just optimising the linear search for capacity with binary search.
    // When we cross the limit of days given, underCapacity returns false and low = mid+1 gets executed.
    // If the capacity is possible then we need to get a lesser capacity if possible so high = mid-1;
    // It is worth noting that in these kinds of binary searches, both low and high end up at opposite of what they were pointing to, if low was pointing to an answer then by the end it will point to the first element that is not the answer and vice versa and same for high.
    // Eg- for {0,0,0,1,1,1,1,1,1,1}, 1 represents possible answers and 0 represents impossible answers, so low starts at first 0 and high starts at last 1, after the end, low ends up at first 1(index 3) and high ends at last 0(index 2), now just choose which answer u want, if it was {1,1,0,0,0} then max possible answer would be high(index 1).
    // In this case, we have {0..1} answers, and we need the first 1(minimum capacity) which is low.
    cout<<optimal(weights, days);

    std::cout<<"\n\n";
    return 0;
}