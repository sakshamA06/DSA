#include<bits/stdc++.h>

void bf(std::vector<std::vector<int>>& mat){
    int n = mat.size(); // number of rows
    int m = mat[0].size(); // number of columns
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                for(int k = 0; k < n; k++){
                    mat[k][j] = -1;
                }
                for(int k = 0; k < n; k++){
                    mat[i][k] = -1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == -1) mat[i][j] = 0;
        }
    }
}

void better(std::vector<std::vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    std::vector<int> row = {m, 1};
    std::vector<int> col = {n, 1};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                col[i] = 0;
                row[j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(col[i] == 0 || row[j] == 0) mat[i][j] = 0;
        }
    }
}

void optimal(std::vector<std::vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    int col0 = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                mat[i][0] = 0; // left most col
                if(j==0) col0 = 0;
                else mat[0][j] = 0; // top most row
            }
        }
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(mat[0][j] == 0 || mat[i][0] == 0) mat[i][j] = 0;
        }
    }
    for(int i = 1; i < m; i++){
        if(mat[0][0] == 0) mat[0][i] = 0;
    }
    for(int i = 1; i < n; i++){
        if(col0 == 0) mat[i][0] = 0;
    }
}

void mySol(std::vector<std::vector<int>>& mat){
    std::vector<std::pair<int, int>> ogz;
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0) ogz.push_back({i, j});
        }
    }
    for(auto it: ogz){
        for(int i = 0; i < n; i++){
            mat[i][it.second] = 0;
        }
        for(int i = 0; i < m; i++){
            mat[it.first][i] = 0;
        }
    }
}

int main(){
    // Given an n*m matrix, if an element is 0 in the original matrix, set its entire row and column to 0.
    // std::vector<std::vector<int>> mat = {{1,1,1}, {1,0,1}, {1,1,1}};
    std::vector<std::vector<int>> mat = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    // Brute Force: O(nm * (n+m)) + O(nm) , O(1)
    // Traverse the matrix, when u find a 0, traverse its row and column to set it -1, and then move on in the matrix. Once this is done, the -1 represents all the places that should be 0, we did not mark rows and columns 0 instantly cuz an earlier 0 might affect a later non-zero and make it 0, and then when we reach that 'later 0', we will start marking its rows and cols 0 too even though it was non-zero in the original.
    // bf(mat);

    // Better Solution: O(2 * nm) , O(n+m)
    // Keep track of the row and columns to be set to 0 by marking it in row and column arrays instead of traversing the entire row/col and marking it -1, we just mark at one place.
    // better(mat);

    // Optimal Solution: O(2 * nm) , O(1)
    // Instead of keeping separate arrays, we embed it inside the matrix in mat[0][] and mat[][0], but the (0, 0) index will conflict so we let the mat[][0] as it is and make col0 variable.
    optimal(mat);

    // My Solution: O(nm) + O((n+m) * number of zeroes(O(n+m) in worst case)) , O(n+m) -> number of zeroes
    // Iterate through the array and store the index of zeroes, then go through these indices and mark the rows and columns 0
    // mySol(mat);

    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }


    std::cout<<"\n\n";
    return 0;
}