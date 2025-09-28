#include<bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<vector<int>>& matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    
    int low = 0;
    int high = m-1;
    while(low <= high){
        int mid = (low+high)/2;
        int colIndex = 0;
        for(int i = 0; i < n; i++){
            if(matrix[mid][i] > matrix[mid][colIndex]) colIndex = i;
        }
        int top = (mid-1 >= 0) ? matrix[mid-1][colIndex] : -1;
        int bottom = (mid+1 < m) ? matrix[mid+1][colIndex] : -1;
        if(matrix[mid][colIndex] > top && matrix[mid][colIndex] > bottom) return {mid, colIndex};
        else if(matrix[mid][colIndex] > top) low = mid+1;
        else high = mid-1;
    }
    return {-1, -1}; // will never actually run but compiler will complaint if flow can reach the end of the function without a return statement
}

int main(){
    vector<vector<int>> matrix = {
        {4,2,5,1,4,5},
        {2,9,3,2,3,2},
        {1,7,6,0,1,3},
        {3,6,2,3,7,2},
        {2,3,4,1,2,8}
    };

    // Brute Force: O(m*n), O(1)
    // Go through each element one by one and check if its the peak
    // OR just find the maximum element in the entire matrix

    // Optimal Solution: O(n * log m), O(1)
    // Pick a middle row, find the maximum element of that row. Now that element is guaranteed to be greater than its horizontal peers, we check if its greater than its top and bottom as well. If it is then its the peak.
    // If the bottom element is greater, then that means that bottom element is greater than every element in the mid row as its greater than the max of the mid row which also means the max element of the row with that bottom element(which might or might not be that bottom element itself) is also greater than every element in the mid row.
    // Say we get mid as 2, so let R2 be row 2, M2 be max element of R2, and BM2 be the element below M2. So BM2 is actually in R3
    // M2 is greater than R2, i.e. every element of R2
    // So if BM2 is greater than M2, then BM2 is greater than R2, so M3 which is greater than or equal to BM2 is also greater than R2, so we can safely say that there's definitely a peak in bottom half and we can eliminate the top half. Similar logic for top element and elimination of bottom half.
    vector<int> index = optimal(matrix);

    cout<<index[0]<<", "<<index[1];

    cout<<"\n\n";
    return 0;
}