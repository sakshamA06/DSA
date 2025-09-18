#include<bits/stdc++.h>
using namespace std;

int helper(long long mid, int n, int x){
    long long ans = 1;
    for(int i = 1; i <= n; i++){
        ans *= mid;
        if(ans > x) return 0;
    }
    if(ans == x) return 1;
    return 2;
}

int optimal(int n, int x){
    int low = 1;
    int high = x;
    while(low <= high){
        long long mid = low + (high-low)/2;
        int midToN = helper(mid, n, x);
        if(midToN == 1) return mid;
        else if(midToN == 2) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main(){
    // Given a number x and n, return the nth root of x if it exists otherwise return -1.
    int n = 4;
    int x = 69;
    
    // Brute Force: O(nth root of x) , O(1)
    // Just do a linear search, similar to last problem.

    // Optimal Solution: O(log n) , O(1)
    // Its mostly similar to square root, main difference is the helper function.
    // This helper function started as just a function that calculates exponents of numbers, but lets say n = 4 and x = INT_MAX, then mid will be x/2 and helper function will try to calculate power 4 of x/2, which will overflow even long long.
    // But we don't need the exact value of this exponentiation, we just wanna know if power 4 of x/2 exists in answer array or not(again this answer array is hypothetical from 1 to x), so we check after each repetitive multiplication if it exceeds x, when it does we know its not in the array and return 0 which means to trim the right half.
    // Since mid is too large that mid^n exceeds x, every element after mid will exceed, so entire right half can never contain the answer which is where binary search shines.
    // If mid^n is x, then that mean x to nth root is mid, so we have found it, so we return 1 from helper function representing we found it.
    // If ans(i.e. = mid^n) is less than x, then we can trim the left half as mid^n < x, every element less than mid will be less than x. We could have stored this mid and then trimmed left half if the problem asked for floor of nth root of x.
    // If mid^n != x ∀ mid, then that means there doesnt exist an integral mid and we return -1;
    cout<<optimal(n, x);


    std::cout<<"\n\n";
    return 0;
}