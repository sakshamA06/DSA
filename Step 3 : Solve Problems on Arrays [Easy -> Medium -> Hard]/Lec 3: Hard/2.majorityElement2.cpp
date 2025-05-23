#include<bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> arr){
    vector<int> majority;
    int n = arr.size();

    int candidate1, candidate2;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < n; i++){
        if(count1 == 0 && candidate2 != arr[i]){
            candidate1 = arr[i];
            count1++;
        }
        else if(count2 == 0 && candidate1 != arr[i]){
            candidate2 = arr[i];
            count2++;
        }
        else if(candidate1 == arr[i]) count1++; // don't make this and if statement, cuz if count1 is 0, then the current element(i.e. arr[i]) will be stored in candidate(incrementing count1 to 1) and this will also run, increasing count1 twice
        else if(candidate2 == arr[i]) count2++;
        else{
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == candidate1) count1++;
        else if(arr[i] == candidate2) count2++;
    }
    if(count1 > (n/3)) majority.push_back(candidate1);
    if(count2 > (n/3)) majority.push_back(candidate2);
    return majority;
}

int main(){
    // Given an array, return all the elements with higher frequency than floor(n/3).
    vector<int> arr = {1,2,1,2,1,1,2,3,4};

    // Quick note: There can only be atmost 2 elements which span more than 1/3rd of the array

    // Brute Force: O(n^2) , O(1)
    // Pick each element, find its frequency by iterating through the array, check if the frequency is greater than floor(n/3), if yes then add it to the answer vector.
    // Either add it to a set to avoid duplicates, or just check if the second majority element matches the first element already added, since 1st element should be added without any checks, and there can't be a third element that needs to be checked against 1st and 2nd elements.

    // Better Solution: O(2n) , O(n)
    // You hear frequency, first better solution might be just a hashmap.
    // Generate the hashmap for the array and iterate through the map to see which elements occur in majority.

    // Optimal Solution: O(2n) , O(1)
    // Bayer Moore's Voting Algorithm:
    // Keep two variables, works similar to Majority I optimal solution, while iterating just check if the current element is equal to any of the variables, if yes increase their count, if no decrement both their count, if one's count becomes 0, change it with the next element(shouldn't be the other element)
    // After the iteration, check if the elements are actually majority since there's no guarantee a majority exists

    for(auto it: optimal(arr)){
        cout<<it<<" ";
    }


    std::cout<<"\n\n";
    return 0;
}