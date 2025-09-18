#include<bits/stdc++.h>
using namespace std;

int countBouquets(vector<int>& bloomDay, int days, int k){
    int b = 0;
    int cnt = 0;
    for(int i = 0; i < bloomDay.size(); i++){
        if(bloomDay[i] <= days) cnt++;
        else cnt = 0;
        if(cnt == k){
            b++;
            cnt = 0;
        }
    }
    return b;
}

int optimal(vector<int>& bloomDay, int m, int k){
    int n = bloomDay.size();
    if(m * k > n) return -1;
    int max = bloomDay[0];
    for(int i = 1; i < n; i++){
        if(bloomDay[i] > max) max = bloomDay[i];
    }
    int low = 1;
    int high = max;
    while(low <= high){
        int mid = low + (high-low)/2;
        int b = countBouquets(bloomDay, mid, k);
        if(b >= m) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    // Given an array of days where bloomDay[i] represents number of days it would take for flower i to bloom, return the minimum number of days so that making m bouquets of k adjacent flowers is possible where the same flower can't be used in more than one bouquet.
    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m = 2;
    int k = 3;
    // after 7 days the bloomed flowers are {1,1,1,1,0,1,1}, we can make the first bouquet from first three flowers, but not the second bouquet cuz we need 3 other adjacent flowers and the other three we have are not adjacent, so the answer would be 12, and choose any 2 adjacent triplet of flowers.

    // Brute Force: O(n + n*(ans-min)) , O(1)
    // Or just start with 1 and keep going until u find the answer for O(n*ans) TC.
    // Possible answer days can be from min(bloomDay) to max(bloomDay).
    // So just check each day from min to max and return the first possible day, it will be minimum.
    // For checking we just see which bloomDay[i] is less than days passed, meaning that i flower has bloomed. Keep a count which represents total number of adjacent flowers till now, once it reaches k, make a bouquet(b++) and start the count again. Also we need to reset count to 0 everytime we find an un-bloomed flower so count only holds number of adjacent flowers.
    // We can also check another way i.e. keep increasing count for bloomed flowers, and when u encounter a un-bloomed flower or the end of array, just add count/k to bouquets.
    
    // Optimal Solution: O(n + n*log(max-min)) , O(1)
    // Or we can just set low = 1 and high = 10^9(1e9) for O(n*log(1e9)) TC.
    // This just replaces the linearity of checking days with a binary search.

    cout<<optimal(bloomDay, m, k);

    std::cout<<"\n\n";
    return 0;
}