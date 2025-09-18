#include<bits/stdc++.h>
using namespace std;

bool possibleDistance(vector<int> stalls, int k, int distance){
    int accDist = 0;
    int cows = 1;
    for(int i = 1; i < stalls.size(); i++){
        accDist += stalls[i] - stalls[i-1];
        if(accDist >= distance){
            cows++;
            accDist = 0;
        }
        if(cows >= k) return true;
    }
    return false;
}

int optimal(vector<int> stalls, int k){
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = *max_element(stalls.begin(), stalls.end());
    while(low <= high){
        int mid = low + (high-low)/2;
        if(possibleDistance(stalls, k, mid)) low = mid+1;
        else high = mid-1;
    }
    return high;
}

int main(){
    // Given an array representing co-ordinates of stalls and k number of aggressive cows. The cows are placed such that minimum distance between them is maximum, or in other words they are as far apart as possible, and return this distance.
    // vector<int> stalls = {0,3,4,10,9,7};
    // int k = 2;
    vector<int> stalls = {1,2,3,4,6};
    int k = 2;

    // Brute Force: O(n*log n + n*max) , O(1)
    // Sort the stalls so that calculating distance between cows is easier.
    // Just check through 1 to max(stalls), the last distance that was possible is the answer.
    // For checking if the distance is possible, just place the first cow at 0th index, and keep checking if the accumulated distance from last cow is greater than or equal to required distance, if it is then place the cow(cows++) and reset the accumulated distance, if not just move on.
    // If at any point we are able to place k cows, we return true, its possible otherwise false.

    // Optimal Solution: O(n*log n + n*log(max)) , O(1)
    // Just improve the linear search for answers with BS, rest is same.
    // Since high starts at max element(last element in a sorted array), and that distance is not possible, it will end up at the last possible distance(or maximum possible distance) so we return this.
    // In the case of 2 cows, high will be pointing to the max distance, but high will never move in this case and low will eventually be equal to stalls.size(), crossing it, so high still points to the last possible answer. Also notice since low started on a possible answer(1), it ends up outside the array cuz there is no impossible answer till max(stalls). By array here i meant the array of answers (1,2,3,4,..,max(stalls)).
    cout<<optimal(stalls, k);

    std::cout<<"\n\n";
    return 0;
}