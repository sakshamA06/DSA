#include<bits/stdc++.h>
using namespace std;

int smallerEquals(vector<vector<int>>& matrix, int num){
    int count = 0;
    for(int i = 0; i < matrix.size(); i++){
        count += upper_bound(matrix[i].begin(), matrix[i].end(), num) - matrix[i].begin();
    }
    return count;
}

int optimal(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    int low = matrix[0][0];
    int high = matrix[0][n-1];
    for(int i = 0; i < m; i++){
        if(matrix[i][0] < low) low =matrix[i][0];
    }
    for(int i = 0; i < m; i++){
        if(matrix[i][n-1] > high) high =matrix[i][n-1];
    }

    while(low <= high){
        int mid = (low+high)/2;
        if(smallerEquals(matrix, mid) > (m*n)/2) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    // Given a row-wise sorted matrix with odd number of total elements, return the median of those elements.
    vector<vector<int>> matrix = {
        {1,5,7,9,11},
        {2,3,4,5,10},
        {9,10,12,14,16}
    };

    // Brute Force: O(m*n + m*n * log m*n), O(m*n)
    // Populate a 1D array with the matrix elements, sort it then return the median which will be on (m*n)/2 index in the array.

    // Optimal Solution: O(2m + log(max-min) * m*log n)
    // We will use the fact that the number of elements on both side of the median will be same and equal to (m*n)/2 as the matrix has odd number of elements.
    // So number of elements smaller than or equal to the median will be atleast (m*n)/2, we just need to find the smallest element which has atleast (m*n)/2 elements smaller than or equal to it.
    // Instead of checking elements of the matrix, we do BS on answers, as the median will be between minimum and maximum of the matrix(both of which can be calculated in O(m) each).
    // Now to find number of elements smaller than or equal to a number, we just add up all the number of elements smaller than or equal to that row in all rows, we can get this number easily using upper bound.
    cout<<optimal(matrix);

    cout<<"\n\n";
    return 0;
}