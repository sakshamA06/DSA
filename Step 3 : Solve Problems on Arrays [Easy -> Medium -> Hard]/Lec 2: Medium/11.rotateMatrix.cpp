#include<bits/stdc++.h>

void bf(std::vector<std::vector<int>>& mat){
    int n = mat.size();
    std::vector<std::vector<int>> rotMat(n, std::vector<int>(n)); // init 2d vec of size n*n

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            rotMat[j][n-i-1] = mat[i][j];
        }
    }

    // just copying it back cuz i dont wanna return rotMat, shouldnt be counted towards TC
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = rotMat[i][j];
        }
    }
}

void optimal(std::vector<std::vector<int>>& mat){
    int n = mat.size();

    // Transposing in place
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){ // Only traverse the bottom left triangle
            std::swap(mat[i][j], mat[j][i]);
        }
    }
    // Reversing entire column order
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n/2; j++){
            std::swap(mat[i][j], mat[i][n-j-1]);
        }
    }
}

int main(){
    // Given an n*n matrix, rotate it by 90 degrees clockwise.
    std::vector<std::vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    // std::vector<std::vector<int>> mat = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    // Brute Force: O(n^2) , O(n^2)
    // Create a new matrix, and copy paste each row to its column from back such that
    // mat[i][] = rotMat[][n-i-1]
    // bf(mat);

    // Optimal Solution: O(n^2) , O(1)
    // TC - First, transpose, there's O(n^2 / 2) cuz its only half diagonally.
    // Then there's O(n^2 / 2) cuz we only go half the row.
    // So it adds upto O(n^2), quite nice.
    
    // By observation of where columns go in og matrix to rot matrix, we see the columns become rows in reverse order.
    // Thought process - columns to rows? thats transpose, and since we want it in reverse, we will reverse columns after transposing as well 
    optimal(mat);

    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat.size(); j++){
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    std::cout<<"\n\n";
    return 0;
}