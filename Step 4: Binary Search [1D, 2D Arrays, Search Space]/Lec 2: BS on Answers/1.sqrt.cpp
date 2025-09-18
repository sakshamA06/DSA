#include<bits/stdc++.h>
using namespace std;

int bf(int n){
    long long i = 1;
    while(true){
        if(i*i > n) return i-1;
        i++;
    }
}

int optimal(int n){
    // int sqrt = -1;
    int low = 1;
    int high = n;
    while(low <= high){
        long long mid = low + (high-low)/2;
        if(mid*mid == n) return mid;
        else if(mid*mid < n){
            // sqrt = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    // return sqrt;
    return high; // explained below.
}

int main(){
    // Given a number, return the floor of its square root.
    int n = 28;

    // Brute Force: O(sqrt(n)) , O(1)
    // Just start with 1 and keep incrementing it and saving it until its square crosses the number, once it does we know the integral square root.
    // cout<<bf(n);

    // Optimal Solution: O(log(n)) , O(1)
    // Binary search the number. For better visualisation we can think that we are searching on a sorted array containing numbers from 1 to n. Ofcourse this array is hypothetical and so these problems are called binary search on answers as we already know the range from which the answer to the problem belongs.(1 to n) in this case.
    // Also since checking mid*mid == n would overflow, divide mid from both sides or take mid as long long.
    cout<<optimal(n);

    // Advanced binary search observation:
    // Notice that the loop will only exit when high < low, but inside the loop high is only updated inside the else statement, with high = mid-1
    // That means the loop will only exit when mid-1 < low(after high gets updated with mid-1)
    // But mid can never have a value strictly lesser than low, at minimum it will be equal to low.
    // So the loop cant exit if mid == low+1, since even if high gets updated, it will only be equal to low, which keeps the loop running.
    // All this is to say loop exits only when mid == low, i.e. high == mid-1 == low-1, so after the loop, high will always be exactly one lesser than low, it cant be any more lesser.
    // Also mid will only be equal to low if high == low+1, which means low and high are adjacent to each other. Now if low is pointing to the answer, when mid becomes low, it will return. If high has the answer then when mid becomes low, the condition mid*mid<n will be true and low will move to high position and next iteration will return answer.
    // But if at low it was not the sqrt but smth lesser than the sqrt then low will move forward and will point to high, then mid will be calulated to point to low, and if its square is greater then that means the last low was the answer. So when mid*mid > n, high = mid-1 will be executed and high will move to the previous low which had the answer.
    // So ultimately we don't need a different sqrt variable, we can just return high in the end if loop exits.

    // And one more thing btw just for perspective, for n = INT_MAX, log n only takes 31 iterations whereas sqrt(n) takes 46341.
    // So optimal solution is much better.

    std::cout<<"\n\n";
    return 0;
}