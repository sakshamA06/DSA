#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bf(vector<int> arr){
    vector<int> triplet;
    set<vector<int>> st;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    triplet = {arr[i], arr[j], arr[k]};
                    sort(triplet.begin(), triplet.end());
                    st.emplace(triplet);
                }
            }
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}

vector<vector<int>> better(vector<int> arr){
    int n = arr.size();
    vector<int> triplet;
    set<vector<int>> st;

    for(int i = 0; i < n; i++){
        set<int> hash = {};
        for(int j = i+1; j < n; j++){
            int k = -(arr[i]+arr[j]);
            if(hash.find(k) != hash.end()){
                triplet = {arr[i], arr[j], k};
                sort(triplet.begin(), triplet.end());
                st.emplace(triplet);
            }
            hash.emplace(arr[j]);
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}

vector<vector<int>> optimal(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            if(arr[i]+arr[j]+arr[k] > 0) k--;
            else if(arr[i]+arr[j]+arr[k] < 0) j++;
            else{
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1]) j++;
                while(j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}

int main(){
    // Given an array of integers, return all the unique triplets formed from its elements that add upto 0. Each element can only be used once.
    vector<int> arr = {-1,0,1,2,-1,-4};

    // Brute Force: O(n^3 * log m) , O(2m) , where m is the number of triplets
    // TC: log m is due to set
    // SC: 2m is cuz of set and the vector used to return the answer
    // Generate all triplets and check if their sum is 0, if yes then sort and add it to a set to avoid duplication.
    // vector<vector<int>> res = bf(arr);

    // Better Solution: O(n^2 * log m) , O(n + 2m)
    // Removing the third for loop for the third element:
    // for a chosen arr[i] and arr[j], there's only one acceptable value of arr[k] which is -(arr[i]+arr[j]) since arr[i]+arr[j]+arr[k] = 0, just take the i and j terms to the right side.
    // So we keep a hash set which tells if the array has the third element or not, but if we keep a normal hash set, then the same element might be counted twice, so we keep the hash set between i and j only as long as j moves to the end and empty it once i moves and rebuild for all the possible j's with the new i.
    // After finding a arr[k], we do the same as before, sort and add it to a set to avoid duplication.
    // vector<vector<int>> res = better(arr);

    // Optimal Solution: O(n^2) , O(m)
    // Now we will try to not use set to avoid duplication.
    // We need a sorted array for this algorithm so sort it.
    // Two pointer approach: One at very left, other at very right. These two represent arr[i] and arr[k]
    // j will start at right after i (i.e. i+1), and we check if the sum is +ve or -ve, if +ve we need to reduce so we will leftshift k, if -ve we need to increase it so we rightshift j.
    // After getting sum of 0, we just add (arr[i],arr[j],arr[k]) and move on.
    // When j equals or crosses k, we restart everything by rightshifting i.
    // Note while shifting any of the three pointers, we will always shift it until it encounters a new element than what it was pointing to before.
    vector<vector<int>> res = optimal(arr);



    for(auto x : res){
        cout<<"{";
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"}\n";
    }

    std::cout<<"\n\n";
    return 0;
}