#include<bits/stdc++.h>
using namespace std;

pair<int, int> optimal(vector<vector<int>> matrix, int key){
    int m = matrix.size();
    int n = matrix[0].size();
    int row = 0;
    int col = n-1;
    while(row < m && col >= 0){
        if(matrix[row][col] == key) return {row, col};
        else if(matrix[row][col] > key) col--;
        else row++;
    }
    return {-1, -1};
}

int main(){
    // Given a matrix sorted row-wise left to right and column-wise top to bottom, return the index of the key if it exists or -1, -1 otherwise
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int key = 131;

    // Brute Force: O(m*n), O(1)
    // Linear search the entire matrix

    // Better Solution: O(m*log n), O(1)
    // Binary search each row one by one

    // Optimal Solution: O(m+n), O(1)
    // Start at top right, if its lesser than key then surely the key cant be to its left as all the elements to its left are smaller, similarly if its larger than the key then surely the key cant be below it in the same column as all the elements below it are larger than it.
    // If it cant be to its left, increase the row number, if it cant be below it, decrease the column number, if at any point you find the key return the index or if row or column go out of bounds then we know the key isnt in the matrix.
    // We can also start at bottom left and do similar reasoning.
    // We cant start at top left or bottom right, as for them the elements are increasing or decreasing in both directions, we cant eliminate one direction. For top right and bottom left, one direction is increasing and the other is decreasing so we can eliminate one of them at each step according to inequality between key and current element.
    pair<int, int> index = optimal(matrix, key);
    
    cout<<index.first<<", "<<index.second;
    
    
    cout<<"\n\n";
    return 0;
}