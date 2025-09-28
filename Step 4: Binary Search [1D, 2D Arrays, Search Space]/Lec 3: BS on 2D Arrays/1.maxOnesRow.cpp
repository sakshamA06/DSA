#include<bits/stdc++.h>
using namespace std;

int optimal(vector<vector<int>> mat){
    int m = mat.size(); // number of rows OR column size
    if(m == 0) return 0;
    int n = mat[0].size(); // number of columns OR row size
    int maxCount = 0;

    for(int i = 0; i < m; i++){
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(mat[i][mid] == 0) low = mid+1;
            else high = mid-1;
        }
        maxCount = max(maxCount, n-low); // low is the first 1 as it started from 0
    }
    return maxCount;
}

int main(){
    // Given a 2d array with only 0s and 1s and each row sorted in itself, return the index of the row with the maximum number of 1s. If multiple rows have same max number of 1s, return the smallest.
    vector<vector<int>> mat = {
        {0,0,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,1,1,1,1}
    };

    // Brute force: O(m*n), O(1)
    // Iterate each row, find the number of 1s, update max if necessary, and after all rows are done, return the max;

    // Optimal Solution: O(m log n), O(1)
    // Iterate each row, binary search the first 1, subtract its index from length of the row to get number of 1s in that row, update max if necessary and return max at the end.
    cout<<optimal(mat);


    cout<<"\n\n";
    return 0;
}