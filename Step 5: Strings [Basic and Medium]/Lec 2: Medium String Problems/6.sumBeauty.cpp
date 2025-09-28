#include<bits/stdc++.h>
using namespace std;

int minGreaterThanZero(vector<int>& hmap){
    int min = INT_MAX;
    for(int i = 0; i < hmap.size(); i++){
        if(hmap[i] != 0 && hmap[i] < min) min = hmap[i];
    }
    if(min == INT_MAX) return 0;
    return min;
}

int optimal(string& s){
    int n = s.size();
    int sum = 0;
    vector<int> hmap(26, 0);
    for(int i = 0; i < n; i++){
        hmap.assign(26, 0);
        int mostF = 0;
        for(int j = i; j < n; j++){
            // [i->j] substring
            int c = s[j]-'a';
            hmap[c]++;
            if(hmap[c] > mostF) mostF = hmap[c];
            sum += mostF - minGreaterThanZero(hmap); // mostF-leastF
        }
    }
    return sum;
}

int main(){
    // Given a string, return the sum of beauty of all its substrings.
    // The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
    string s = "aabcbaa";

    // Optimal Solution: O(n^2 * 26), O(1)
    // For each substring, while adding a new character, we check if it exceeds frequency of the most frequent character(i.e. mostF). And also calculate the least frequency greater than 0 each time as there is no reliable way to know how the least frequent element will change.
    // Keep adding beauty(mostF-leastF) for each substring and return at the end.
    cout<<optimal(s);

    cout<<"\n\n";
    return 0;
}