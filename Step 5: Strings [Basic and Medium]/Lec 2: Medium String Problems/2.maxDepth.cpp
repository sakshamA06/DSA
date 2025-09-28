#include<bits/stdc++.h>
using namespace std;

int optimal(string& s){
    int depth = 0;
    int maxDepth = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(') depth++;
        else if(s[i] == ')') depth--;
        maxDepth = max(maxDepth, depth);
    }
    return maxDepth;
}

int main(){
    // Given a valid parenthesis string, return the maximum nested depth.
    string s = "(1+(2*3)+((8)/4))+1";

    // Optimal Solution: O(n), O(1)
    // Just keep a depth variable, which will increase for (, as ( means increasing the nesting and decrease for ), as ) means decreasing the nesting. Keep track of max value that depth ever reached with another variable.

    cout<<"\n\n";
    return 0;
}