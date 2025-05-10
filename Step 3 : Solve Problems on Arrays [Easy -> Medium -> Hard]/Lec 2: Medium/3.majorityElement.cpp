#include<bits/stdc++.h>

int bf(std::vector<int> arr){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]) count++;
        }
        if(count > n/2) return arr[i];
    }
    return -1;
}

int better(std::vector<int> arr){
    std::map<int, int> hmap;
    for(int i = 0; i < arr.size(); i++){
        hmap[arr[i]]++;
    }
    for(auto it: hmap){
        if(it.second > arr.size()/2) return it.first;
    }
    return -1;
}

int optimal(std::vector<int> arr){
    int count = 0;
    int candidate;
    for(int i = 0; i < arr.size(); i++){
        if(count == 0){
            candidate = arr[i];
            count++;
        }
        if(arr[i] == candidate) count++;
        else count--;
    }
    count = 0; // reusing the same variable to actually count for candidate's frequency now
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == candidate) count++;
    }
    if(count > arr.size()/2) return candidate;
    else return -1;
}

int main(){
    // Given an array, return the element which occurs in majority if it exists or -1 if there is no majority.
    // Majority is when the element's frequency > n/2 and not when its frequency is higher than every other element. For example {1, 1, 2, 3} has no majority cuz n/2 is 2, and 1 occurs 2 times, not greater than 2(i.e. n/2)
    std::vector<int> arr = {2, 2, 3, 3, 1, 2, 2};

    // Brute Force: O(n^2) , O(1)
    // Pick an element, iterate through the array to find its frequency, if its > n/2 then return it, otherwise pick the next element and do the same, and so on for the entire array.
    // std::cout<<bf(arr);

    // Better Solution: O(n log n) , O(n)
    // TC: Same TC analysis for maps, depending on ordered or unordered.
    // SC: O(n) for hashmap
    // Use a hashmap and iterate through the map to find if frequency of any element is greater than n/2
    // std::cout<<better(arr);

    // Optimal Solution:
    // Moore's Voting algo
    // Pick an candidate(initially undefined for reasons explained later, candidate is just the term used for currently picked element), keep a count(does not represent frequency of candidate) and increment it whenever u see candidate, and decrement it whenever u see any other element.
    // When count reaches 0, change the candidate to whatever element made it 0.
    // After iterating through the array, either candidate will be majority or there will be no majority.
    // Now not picking the first element to be candidate is simply for the case that array is empty, and so that the code is more robust.
    std::cout<<optimal(arr);

    std::cout<<"\n\n";
    return 0;
}