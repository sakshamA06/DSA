#include<bits/stdc++.h>
using namespace std;

string optimal1(vector<string> strs){
    int n = strs.size();
    string prefix = "";
    for(int i = 0; i < strs[0].size(); i++){
        bool same = true;
        for(int j = 1; j < n; j++){
            if(strs[j][i] != strs[0][i]) same = false;
        }
        if(same) prefix += strs[0][i];
        else break;
    }
    return prefix;
}

string optimal2(vector<string> strs){
    int n = strs.size();
    string prefix = strs[0];
    for(int i = 1; i < n; i++){
        int j = 0;
        while(j < strs[i].size() && strs[i][j] == prefix[j]){
            j++;
        }
        prefix.resize(j);
        if(prefix.size() == 0) return "";
    }
    return prefix;
}

int main(){
    // Given an array of strings, determine the longest common prefix among all the strings. Its not common substring, common prefix means the first k letters should be same for a prefix of length k.
    vector<string> strs = {"flower","flow","flight"};

    // Optimal Solution 1: O(strs[0].length * n), O(prefix)
    // SC is only for returning the answer
    // Iterate through the first string, and for every character, check if its present in other strings at the same position as well.
    // cout<<optimal1(strs);

    // Optimal Solution 2: O(total number of characters in all the strings), O(strs[0])
    // Keep a prefix string initialized to first string and check with second string when they differ, when they do, that means till now we had common characters, shorten the prefix to that much and then continue doing it with other strings.
    cout<<optimal2(strs);

    cout<<"\n\n";
    return 0;
}