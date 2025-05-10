#include<bits/stdc++.h>

std::vector<int> optimal(std::vector<std::vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    std::vector<int> arr; // better to just push back than fix size here since otherwise you'd have to keep track of index to populate this array.

    int top = 0;
    int left = 0;
    int right = m-1;
    int bottom = n-1;

    while(top <= bottom && left <= right){
        // left -> right in top row
        for(int i = left; i <= right; i++)
            arr.push_back(mat[top][i]);
        top++; // move top one down

        // top -> bottom in right col
        for(int i = top; i <= bottom; i++)
            arr.push_back(mat[i][right]);
        right--; // move right one left

        if(top <= bottom){
            // right -> left in bottom row
            for(int i = right; i >= left; i--)
                arr.push_back(mat[bottom][i]);
            bottom--; // move bottom one up
        }

        if(left <= right){
            // bottom -> top in left col
            for(int i = bottom; i >= top; i--)
                arr.push_back(mat[i][left]);
            left++; // move left one right
        }
    }

    return arr;
}

int main(){
    // Given an n*m matrix, return an array with its elements in spiral order.
    // Spiral order means start from 0,0 go right, then down, and keep turning clockwise.
    std::vector<std::vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};

    // Optimal Solution: O(nm) , O(nm)
    // Traverse around in a ring pattern, and keep decreasing the ring's size.
    // This ring is referred to as box in my lingo. Actually even the ring is my lingo only lol.
    // for one stroll around the box:
    // left -> right in top row, move top one down
    // top -> bottom in right col, move right one left
    // right -> left in bottom row, move bottom one up, only move if top<=bottom i.e. a horizontal line exists for it to go left on
    // bottom -> top in left col, move left one right, similarly only move if left<=right i.e. a vertical line exists for it to go up on
    // no need to separately check condition for top two movements as their for loop condition already checks for it
    // the while loop condition ensures the stroll only runs if there is atleast one element left to traverse since top > bottom || left > right means the box has collapsed 

    std::vector<int> res = optimal(mat);

    for(auto it:res) std::cout<<it<<" ";

    std::cout<<"\n\n";
    return 0;
}