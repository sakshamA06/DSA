#include<bits/stdc++.h>

void better(std::vector<int>& arr){
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
        // could have been made one liner if the 3 variables were in an hash map hmap[arr[i]++]
    }
    int i = 0;
    while(count0--){
        arr[i] = 0;
        i++;
    }
    while(count1--){
        arr[i] = 1;
        i++;
    }
    while(count2--){
        arr[i] = 2;
        i++;
    }
}

void optimal(std::vector<int>& arr){
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;
    while(mid<=high){
        if(arr[mid] == 0){
            int temp = arr[mid];
            arr[mid] = arr[low];
            arr[low] = temp;
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            int temp = arr[mid];
            arr[mid] = arr[high];
            arr[high] = temp;
            high--;
        }
    }
}

int main(){
    // Given an array containing only 0, 1 and 2, sort it.
    std::vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    // Brute Force: O(n log n) , O(1)
    // Sort the array using a typical sort like quick sort

    // Better Solution: O(2n) , O(1)
    // Iterate through and count the number of 0s, 1s and 2s, then re-iterate and overwrite each of em according to their frequency.
    // better(arr);

    // Optimal Solution: O(n) , O(1)
    // Dutch National Flag Algorithm
    // Three pointers, low, mid and high
    // 0 to low-1 is all 0s
    // low to mid-1 is all 1s
    // mid to high is unsorted
    // high+1 to n-1 is all 2s
    // This algo basically shifts all 0s to the left and all 2s to the right.
    // if arr[mid] is 0, then replace it with low and move both so that the unsorted portion decreases and the low-1 now is a 0
    // if arr[mid] is 1, just move it forward(then mid-1 will still have a 1 and the size of sorted portion before mid will increase)
    // if arr[mid] is 2, swap it with high, and left shift high so that high+1 now has an additional 2
    optimal(arr);


    for(int i = 0; i < arr.size(); i++){
        std::cout<<arr[i]<<" ";
    }

    std::cout<<"\n\n";
    return 0;
}