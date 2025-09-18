#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bf(vector<int> arr, int target){
    vector<int> quad;
    set<vector<int>> st;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                for(int l = k+1; l < n; l++){
                    if(arr[i] + arr[j] + arr[k] + arr[l] == target){
                        quad = {arr[i], arr[j], arr[k], arr[l]};
                        sort(quad.begin(), quad.end());
                        st.emplace(quad);
                    }
                }
            }
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}

vector<vector<int>> better(vector<int> arr, int target){
    int n = arr.size();
    vector<int> quad;
    set<vector<int>> st;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            set<int> hash = {};
            for(int k = j+1; k < n; k++){
                int fourth = target-(arr[i]+arr[j]+arr[k]);
                if(hash.find(fourth) != hash.end()){
                    quad = {arr[i], arr[j], arr[k], fourth};
                    sort(quad.begin(), quad.end());
                    st.emplace(quad);
                }
                hash.emplace(arr[k]);
            }
        }
    }
    return vector<vector<int>> (st.begin(), st.end());
}

vector<vector<int>> optimal(vector<int>& arr, int target){
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i+1; j < n; j++){
            if(j > i+1 && arr[j] == arr[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                if(arr[i]+arr[j]+arr[k]+arr[l] > target) l--;
                else if(arr[i]+arr[j]+arr[k]+arr[l] < target) k++;
                else{
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main(){
    // Given an array of integers, return all the unique quads formed from its elements that add upto target. Each element can only be used once.
    vector<int> arr = {-2,-1,-1,1,1,2,2};
    int target = 0;

    // Brute Force: O(n^4 * log m) , O(2m) , where m is the number of quads
    // TC: log m is due to set
    // SC: 2m is cuz of set and the vector used to return the answer
    // Generate all quads and check if their sum is target, if yes then sort and add it to a set to avoid duplication.
    // vector<vector<int>> res = bf(arr, target);

    // Better Solution: O(n^2 * log m) , O(n + 2m)
    // Removing the fourth for loop for the fourth element:
    // for a chosen arr[i], arr[j] and arr[k], there's only one acceptable value of arr[l] which is target-(arr[i]+arr[j]+arr[k]).
    // So we keep a hash set which tells if the array has the fourth element or not, but if we keep a normal hash set, then the same element might be counted twice, so we keep the hash set between j and k only as long as k moves to the end and empty it once j moves and rebuild for all the possible k's with the new j.
    // After j has traversed, we move i and rinse and repeat.
    // After finding an arr[l], we do the same as before, sort and add it to a set to avoid duplication.
    // vector<vector<int>> res = better(arr, target);

    // Optimal Solution: O(n^3) , O(m)
    // Same as three sum, just introduce one more loop, basically running three sum repeatedly on other three elements after iterating first element one by one.
    vector<vector<int>> res = optimal(arr, target);



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