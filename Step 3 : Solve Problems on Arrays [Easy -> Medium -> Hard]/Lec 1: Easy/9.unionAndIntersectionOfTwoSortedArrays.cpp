#include<bits/stdc++.h>

// Disclaimer: Some parts of this solution assume one thing like intersection is a set not an array, but optimal solution assumes it an array and so can have duplicates

int main(){
    // Given two sorted arrays of sizes n1 and n2, find their union and intersection
    int n1 = 6;
    int n2 = 5;
    int arr1[n1] = {1, 1, 2, 3, 4, 5};
    int arr2[n2] = {2, 3, 4, 4, 5};
    // union = {1, 2, 3, 4, 5}
    // intersection = {2, 3, 4, 5}
    std::set<int> onion;
    std::set<int> intersection;
    std::vector<int> un;
    std::vector<int> itn;

    // Brute Force:
    // Union: O(n1^2 + n2^2) in worst case , O(1)
    // For every element in arr1, check if it exists in union array, if not then add it, do the same for arr2
    // TC: if every element is unique the second loop will run for 0, 1, 2, 3, .. , n1-1 times, overall is n1(n1+1) / 2, so n1^2 / 2 so n1^2, same for n2
    // Intersection: O(nm) , O(1)
    // For every element in arr1, check if its in arr2, if found then check if it exists in intersection array, if not then add it

    // // Union:
    // for(int i = 0; i < n1; i++){
    //     bool exists = false;
    //     for(int j = 0; j < un.size(); j++){
    //         if(arr1[i] == un[j]){
    //             exists = true;
    //             break;
    //         }
    //     }
    //     if(!exists) un.push_back(arr1[i]);
    // }
    // for(int i = 0; i < n2; i++){
    //     bool exists = false;
    //     for(int j = 0; j < un.size(); j++){
    //         if(arr2[i] == un[j]){
    //             exists = true;
    //             break;
    //         }
    //     }
    //     if(!exists) un.push_back(arr2[i]);
    // }
    // // Intersection:
    // for(int i = 0; i < n1; i++){
    //     for(int j = 0; j < n2; j++){
    //         if(arr1[i] == arr2[j]){
    //             bool exists = false;
    //             for(int k = 0; k < i.size(); k++){
    //                 if(arr1[i] == i[k]){
    //                     exists = true;
    //                     break;
    //                 }
    //             }
    //             if(!exists) itn.push_back(arr1[i]);
    //         }
    //     }
    // }

    // Brute Force: O(n1 log n + n2 log n) , O(n1+n2) {n is the current size of set}
    // for(int i = 0; i < n1; i++){
    //     onion.emplace(arr1[i]);
    // }
    // for(int i = 0; i < n2; i++){
    //     onion.emplace(arr2[i]);
    // }
    // for(auto it : onion){ // O(n1+n2) but this TC is for returning the answer, same SC too
    //     un.push_back(it);
    // }

    // for(int i = 0, j = 0; i < n1;){
    //     if(arr1[i] == arr2[j]){
    //         if(intersection.find(arr1[i]) == intersection.end())
    //             intersection.emplace(arr1[i]);
    //         i++; j++;
    //     }
    //     else if(arr1[i] < arr2[j]) i++;
    //     else j++;
    // }

    // Optimal Solution:
    // Union : O(n1+n2) , O(1)
    // Two pointer method:
    // One for first array, another for second. We compare elements at both pointers to see which is smaller and add that to union, then move the pointer pointing to smaller element and check again, also check if we just added that element to check for duplicates, if found just move the pointer without doing anything.
    // This works because both arrays are sorted, if we are gonna get a duplicate, it always will have been added last to union array, so just need to check with its last element if the current element is same(duplicate) or not(unique).
    // After one of the arrays is finished, we can add the remaining elements of the other array without checking anything except for duplicates.

    int i = 0;
    int j = 0; 
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            if(un.size() == 0 || un.back() != arr1[i])
            un.push_back(arr1[i]);
            i++;
        }
        else {
            if(un.size() == 0 || un.back() != arr2[j])
            un.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        if(un.size() == 0 || un.back() != arr1[i])
        un.push_back(arr1[i]);
        i++;
    }
    while(j<n2){
        if(un.size() == 0 || un.back() != arr2[j])
        un.push_back(arr2[j]);
        j++;
    }

    // Intersection: O(n1+n2) , O(1)
    // Move first pointer if its element is smaller, cuz second pointer is pointing to a larger number and we might find it if we keep moving first pointer, so we wont move second pointer, and similar for if second pointer has smaller element, move it.
    // If the elements are equal then add it to array and move both pointers
    i = 0;
    j = 0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]) i++;
        else if(arr2[j] < arr1[i]) j++;
        else {
            itn.push_back(arr1[i]);
            i++;
            j++;
        }
    }


    for(auto it : un){
        std::cout<<it<<" ";
    }
    std::cout<<"\n";
    for(auto it : itn){
        std::cout<<it<<" ";
    }


    std::cout<<"\n\n";
    return 0;
}