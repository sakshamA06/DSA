#include<bits/stdc++.h>
using namespace std;

bool optimal(string& s, string& goal){
    return (s.size() == goal.size()) && ((s+s).find(goal) != -1);
}

int main(){
    // Given a string s, return whether another string goal can be created using it via rotations.
    string s = "abcde";
    string goal = "deabc";

    // Optimal Solution:
    // Key insight is s+s contains every possible rotation of s, so just search the substring goal in it, if found then goal is rotated version of s, otherwise not.
    cout<<(optimal(s, goal) ? "True" : "False");

    cout<<"\n\n";
    return 0;
}