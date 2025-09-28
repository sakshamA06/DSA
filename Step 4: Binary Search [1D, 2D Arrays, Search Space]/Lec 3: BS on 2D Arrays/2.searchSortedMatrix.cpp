#include<bits/stdc++.h>
using namespace std;

pair<int, int> optimal1(vector<vector<int>>& matrix, int key){
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(matrix[mid][n-1] == key) return {mid, n-1};
        else if(matrix[mid][n-1] > key) high = mid-1;
        else low = mid+1;
    }
    // Now low started with the row with last value smaller than key, it will end up at the row with last element larger than key such that just the previous row's last element will be smaller than key. Hence low is the potential row which has the key, now we search on it.
    if(low == m) return {-1, -1}; // if key is larger than last row's last element then the 'low' row will end up outside the matrix
    int row = low;
    low = 0;
    high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(matrix[row][mid] == key) return {row, mid};
        else if(matrix[row][mid] > key) high = mid-1;
        else low = mid+1;
    }
    return {-1, -1};
}

pair<int, int> optimal2(vector<vector<int>>& matrix, int key) {
    int m = matrix.size();
    int n = matrix[0].size();
    int low = 0;
    int high = m*n-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(matrix[mid/n][mid%n] == key) return {mid/n, mid%n};
        else if(matrix[mid/n][mid%n] < key) low = mid+1;
        else high = mid-1;
    }
    return {-1, -1};
}

int main(){
    // Given a sorted matrix, row wise, and last element of current row is smaller than first element of next row, search for a key's index.
    vector<vector<int>> matrix = {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };
    int key = 30;
    // Brute Force: O(m*n), O(1)
    // Linear search it row by row

    // Optimal Solution: log(m*n), O(1)
    // Binary search:
    // First way: Search only the last column for lower bound of key, this will get you the row in which the key potentially lies, then search that row.
    // pair<int, int> index = optimal1(matrix, key);
    
    // Second way: Consider the entire matrix as a 1d array where the first element of a row comes after the last element of previous, and just use / and % to interconvert the indices between the two.
    pair<int, int> index = optimal2(matrix, key);
    
    cout<<index.first<<", "<<index.second;

    cout<<"\n\n";
    return 0;
}