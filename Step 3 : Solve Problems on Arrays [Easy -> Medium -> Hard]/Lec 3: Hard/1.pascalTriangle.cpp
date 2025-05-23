#include<bits/stdc++.h>
using namespace std;

long long nCr(int n, int r){
    long long ans = 1;
    for(int i = 0; i < r; i++){
        ans *= n-i;
        ans /= i+1;
    }
    // nCr = n * n-1 * n-2 * .../ 1 * 2 * 3 * ....
    // doing it in this order will never mess up with integer division as first it will be n/1 then n(n-1)/2 (2 will divide one of n or n-1) then n(n-1)(n-2)/2*3 (3 will divide one of n or n-1 or n-2) and so on
    // if we divided by r then r-1 and so on, we might have run into the floor calculation for integer division
    return ans;
}

long long optimal1(int r, int c){
    return nCr(r-1, c-1);
}
vector<int> bf2(int r){
    vector<int> row;
    for(int i = 1; i <= r; i++){
        row.push_back(optimal1(r, i));
    }
    return row;
}

vector<int> optimal2(int r){
    vector<int> row = {1};
    int ans = 1;
    for(int i = 1; i < r; i++){
        ans *= r-i;
        ans /= i;
        row.push_back(ans);
    }
    return row;
}

vector<vector<int>> bf3(int n){
    vector<vector<int>> triangle;
    for(int i = 1; i <= n; i++){
        triangle.push_back(optimal2(i));
    }
    return triangle;
}

vector<vector<int>> mySol(int k){
    vector<vector<int>> pt;
    vector<int> prow = {1};
    vector<int> crow;
    pt.push_back(prow);

    for(int row = 0; row < k; row++){
        crow.push_back(1);
        for(int i = 1; i < prow.size(); i++){
            crow.push_back(prow[i-1] + prow[i]);
        }
        crow.push_back(1);
        pt.push_back(crow);
        prow = crow;
        crow = {};
    }
    return pt;
}

int main(){
    // Given the number of rows, return:
    // 1. An element of row r and column c.
    // 2. The row r
    // 3. n rows of the entire triangle 
    int r = 5, c = 3;
    int n = 6;

    // 1. Optimal Solution: O(c) , O(1)
    // Any element can be given by (r-1)C(c-1), this is nCr
    // std::cout<<optimal1(r, c);
    // 2. Brute Force: O(c * r) , O(1) -> O(r) used for returning the answer
    // Generate entire row using the above formula
    // for(auto it: bf2(r)) std::cout<<it<<" ";
    // 2. Optimal Solution: O(r) , O(1) -> O(r) used for returning the answer
    // Same optimisation as the one done to get sum of subarrays, which basically states no need to re-iterate over entire thing if the only change is one new element per iteration, just encompass it in your result.
    // for(auto it: optimal2(r)) std::cout<<it<<" ";
    // 3. Optimal Solution: O(r * n) , O(n)
    // Generate each row and push it in the triangle
    
    for(auto x: bf3(n)){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    std::cout<<"\n\n";
    return 0;
}