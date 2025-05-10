#include<bits/stdc++.h>

int bf(std::vector<int> arr){
    int longest = 0;
    for(int i = 0; i < arr.size(); i++){
        int count = 1;
        int x = arr[i] + 1;
        bool ls = true;
        while(ls){
            ls = false;
            for(int j = 0; j < arr.size(); j++){
                if(arr[j] == x){
                    count++;
                    x++;
                    ls = true;
                    break;
                }
            }
        }
        if(count > longest) longest = count;
    }
    return longest;
}

int better(std::vector<int> arr){
    sort(arr.begin(), arr.end());
    int longest = 0;
    int lastElement = arr[0];
    int count = 1;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] == lastElement+1){
            count++;
            lastElement++;
        }
        else if(arr[i] != lastElement){
            lastElement = arr[i];
            count = 1;
        }
        longest = std::max(longest, count);
    }
    return longest;
}

int optimal(std::vector<int> arr){
    std::unordered_set<int> stt;
    int longest = 1;
    for(int i = 0; i < arr.size(); i++){
        stt.emplace(arr[i]);
    }
    for(auto it: stt){
        if(stt.find(it-1) == stt.end()){
            int count = 1;
            while(stt.find(it+count) != stt.end()) count++;
            if(count > longest) longest = count;
        }
    }
    return longest;
}

int main(){
    // Given an array, return the size of longest sequence that can be formed from it.
    // There may be repetitions.
    std::vector<int> arr = {100, 1, 101, 4, 3, 102, 2, 2};

    // Brute Force: O(n^2) , O(1)
    // Pick an element and linear search through its consecutive elements. Keep on picking elements across the array while keeping the longest count updated.
    // std::cout<<bf(arr);

    // Better Solution: O(n log n) + O(n) , O(1) but its O(n) if you consider the distortion of original array.
    // Sort the array, and itexrate through it only increasing count when we encounter a unique element which can continue the sequence, and updating longest accordingly.
    // std::cout<<better(arr);

    // Optimal Solution: O(3n) , O(n)
    // Add all elements in a set to remove duplicates, now for every element check if its predecessor exists, if yes then move on to next element, if no then that means this element is the start of a sequence if there exists one with this element, then simply check for this sequence and its length. Keep doing this with every element and keep track of longest, this is slightly better cuz we won't check the sequence length if the element is in the middle of it, since the sequence could easily have been longer if we started with the first element.
    std::cout<<optimal(arr);

    std::cout<<"\n\n";
    return 0;
}