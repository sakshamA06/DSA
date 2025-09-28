#include<bits/stdc++.h>
using namespace std;

string optimal(string s) {
    string removed = "";
    int bracketCount = 0;
    for(int i=0; s[i] != 0; i++){
        if(s[i] == '('){
            if(bracketCount) removed += '(';
            bracketCount++;
        }
        else{
            if(bracketCount != 1) removed += ')';
            bracketCount--;
        }
    }
    return removed;
}

int main(){
    // Given a valid parenthesis string, remove the outermost brackets.
    string str = "(()())(())(()(()))";
    // should return ()()()()(())
    // Explanation: Og string can be written as (()()) + (()) + (()(()))
    // Now remove outer brackets of each subgroup and you get the answer

    // Optimal Solution: O(n), O(n)
    // Just keep a count of whether you have seen exactly 1 opening parenthesis and then if in this state you encounter a closing bracket, skip it. Also if count is 0 meaning all opening parenthesis have been closed or we just started then ignore the next first opening parenthesis and ofcourse update count.
    cout<<optimal(str);

    cout<<"\n\n";
    return 0;
}