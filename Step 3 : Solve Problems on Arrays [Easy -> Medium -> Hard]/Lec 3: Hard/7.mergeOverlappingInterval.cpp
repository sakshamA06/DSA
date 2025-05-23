#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> bf(vector<vector<int>> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1]) continue;
        for(int j = i+1; j < n; j++){
            if(arr[j][0] <= end) end = max(end, arr[j][1]);
            else break;
        }
        ans.push_back({start, end});
    }
    return ans;
}

vector<vector<int>> optimal(vector<vector<int>> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        if(!ans.empty() && arr[i][0] <= ans.back()[1])
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        else ans.push_back(arr[i]);
    }
    return ans;
}

int main(){
    // Given an array of intervals, merge all the overlapping subintervals. [1,3] and [3,5] are considered overlapping and should be merged to [1,5]
    vector<vector<int>> arr = {{10,14},{1,3},{2,6},{8,10},{15,20},{4,7}};

    // Brute Force: O(n*log n + 2n) , O(n)
    // TC: Its not O(n^2) cuz each element(except first) is visited twice, once for checking if its overlapping with a previous interval(in the previous interval's loop) and again when its own loop starts. Basically the break and continue statements reduce TC to O(2n), and n*log n for sorting
    // Sort the array first.
    // Eg - {{1,3},{2,6},{4,7},{8,10},{10,14},{15,20}}
    // Pick an interval, and two variables start and end which will be initialized with min and max of picked interval and they will track the min and max of final overlapped interval.
    // Run a loop to check if any of the successor intervals are overlapping with it, they are overlapping if current interval max(end) is greater than the following intervals min. If they are merging, update end to the larger max between the two intervals.
    // Also check in starting whether the current interval is already totally inside the already generated overlapped interval. For eg after the loop runs for {1,3}, the overlapped interval added to answer array would be {1,7}, now when the loop runs for {2,6} this interval is already inside so if end(6) <= last interval's max(7) then its already included and we can move on.
    // vector<vector<int>> res = bf(arr);

    // Optimal Solution: O(n*log n + n) , O(n)
    // Sort and do it in one pass. Keep checking if the current interval can be assimilated into the last added interval, if yes then merge it otherwise add a new interval and we wont have any problems because we sorted it beforehand.
    vector<vector<int>> res = optimal(arr);


    cout<<"{";
    for(auto x: res){
        cout<<"{";
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<"}, ";
    }
    cout<<"}\n";

    std::cout<<"\n\n";
    return 0;
}