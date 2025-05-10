#include<bits/stdc++.h>

std::vector<int> optimal(std::vector<int> arr){
    std::vector<int> leaders;
    int max = arr.back();
    leaders.push_back(max);
    for(int i = arr.size()-2; i >= 0; i--){
        if(arr[i] > max){
            max = arr[i];
            leaders.push_back(arr[i]);
        }
    }
    return leaders;
}

int main(){
    // Given an array, return an array of leaders in it.
    // A leader is an element with all the elements to its right smaller than itself.
    std::vector<int> arr = {10, 22, 12, 3, 0, 6};

    // Brute Force: O(n^2) , O(1)
    // O(n) space is only used to return the answer.
    // Pick an element, iterate through its right to check if its greater than every element, if yes then add it to leader array. Then move to the next element and repeat.
    // Very basic problem, so won't write brute force.

    // Optimal Solution: O(n) , O(1)
    // Start from right and move left, and keep track of max value till now, if the current value is greater, then its greater than every other value to its right and hence add it to leader and update the max value.
    std::vector<int> res = optimal(arr);

    for(auto it: res){
        std::cout<<it<<" ";
    }



    std::cout<<"\n\n";
    return 0;
}