#include<bits/stdc++.h>

int main(){
    // Given an array of size n, move all zeroes to end, if any.
    int n = 8;
    int arr[n] = {1, 0, 2, 4, 0, 0, 1, 3};

    // Brute Force: O(2n), O(n)
    // Create a temp array with all non zeroes, copy it to original, and fill the rest with zeroes
    // Worst Case for SC is no zero in the array, so the entire array is copied to temp and then copied back

    // std::vector<int> temp;
    // for(int i = 0; i < n; i++){
    //     if(arr[i] != 0) temp.push_back(arr[i]);
    // }
    // for(int i = 0; i < temp.size(); i++){
    //     arr[i] = temp[i];
    // }
    // for(int i = temp.size(); i < n; i++){
    //     arr[i] = 0;
    // }

    // Optimal Solution: O(n) , O(1)
    // Using two pointers, first one always points to a 0, and the other traverses the array searching for non-zeroes, when found they swap elements, and first pointer moves forward.(first will always point to next zero when moving one forward because if next element wasnt zero, it would have been selected by second and swapped with first which would make the element next to first pointer a zero and it would move to it)

    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    // if(j == -1) return from here since no zeroes present
    for(int i = j+1; i<n; i++){
        if(arr[i] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }

    for(int i = 0; i < n; i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\n\n";
    return 0;
}