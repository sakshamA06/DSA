#include<bits/stdc++.h>

int main(){
    // Given a sorted array of size n, remove duplicates in place
    int n = 7;
    int arr[n] = {1, 1, 2, 2, 2, 3, 4}; // re-order it like {1, 2, 3, 4, .. , .. , ..} the dotted indices don't matter, can be anything and return the number of unique elements

    // Brute force: O(n * log n + n) , O(n)
    // Traverse it and add each element to a set, and then re-fill the array with this set and work done since sets only have unique elements.
    // std::set<int> unique;
    // for(int i = 0; i < n; i++){
    //     unique.insert(arr[i]); // O(n * log n) , O(n)
    // }
    // int i = 0;
    // for(auto it : unique){ // O(n)
    //     arr[i] = it;
    //     i++;
    // }
    // return i after this as it contains the number of unique elements
    // if the array has become {1, 2, 3, 4, 2, 3, 4}, then at the end i will be at 4th index pointing to 2, so i is number of unique elements

    // Optimal Solution: O(n) , O(1)
    // Traverse the array with two pointers, first one update the starting portion of array and second traverses array to check for unique element, whenever it finds one, the first pointer moves forward and updates that index. 
    for(int i = 0, j = 1; j < n; j++){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
    }
    // return i+1 after this as number of unique elements

    for(int i = 0; i < n; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\n\n";
    return 0;
}