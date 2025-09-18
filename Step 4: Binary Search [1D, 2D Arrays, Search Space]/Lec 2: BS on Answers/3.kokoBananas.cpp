#include<bits/stdc++.h>
using namespace std;

int possible(vector<int>& piles, int h, int k){
    for(int i = 0; i < piles.size(); i++){
        h -= (piles[i]+k-1)/k;
        if(h<0) return 2;
    }
    return 0;
}

int optimal(vector<int>& piles, int h) {
    int max = piles[0];
    for(int i = 1; i < piles.size(); i++){
        if(piles[i] > max) max = piles[i];
    }
    int low = 1;
    int high = max;
    while(low <= high){
        int mid = low + (high-low)/2;
        int p = possible(piles, h, mid);
        if(p == 0) high = mid-1;
        else low = mid+1; 
    }
    return low;
}

int main(){
    // Given a pile of bananas, koko eats k bananas/hr, and koko can't eat from two piles at the same time, so if she eates 3 b/hr, she will take 3 hrs to eat two piles of 4 and 3 bananas.
    // Given the time limit as h hours, return the minimum k so that koko can eat the slowest but still finish the pile. Also there will always be more hours given than piles, to guarantee there exists a k.
    vector<int> piles = {3,6,7,11};
    int h = 8;

    // Brute Force: O(k * n) , O(1)
    // Start from k = 1 and keep going while checking if this k is enough speed. The first k that is fast enough is the answer.

    // Optimal Solution: O(n + n * log (max(piles))) , O(1)
    // Same principle as previous, we know the answer can be from 1 to maximum number of bananas in the piles. Actually any number higher will result in a finished pile too but we need smallest number.
    // Now just do a binary search from 1 to max(piles). We move left whenever we found a k that works since we need the smallest, we move right when k is not enough and we need to increase it.
    // The possible function just checks if the k is possible or not, i.e. whether the piles will be finished or not. It does this by traversing through the pile and subtracting the number of hours each individual pile will take.
    // Mathematically (piles[i]+k-1)/k is just ceil(piles[i]/k). If h<0 then speed(k) should be higher, if h>=0 then this speed works and we should work to find a lower one by eliminating right half.
    // Lets say 5 is the answer, then low = 5, and high = 6, mid = 5, and after checking 5 works, we do high = mid-1 (= 4)
    // In this one, low(5) holds the answer since after loop ends, high will point to low-1(4), which had to be mid in the previous iteration for low to be where it is rn(5), and if 4 was the answer then when mid was 4, high would have become 3 instead of low becoming 5. So 5 is the answer and low has that value.
    cout<<optimal(piles, h);


    std::cout<<"\n\n";
    return 0;
}