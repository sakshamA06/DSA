#include<bits/stdc++.h>
using namespace std;

bool optimal(string& s, string& t) {
    if(s.size() != t.size()) return false;
    int hashmap1[26] = {0};
    int hashmap2[26] = {0};
    for(int i = 0; i < s.size(); i++) hashmap1[s[i] - 'a']++;
    for(int i = 0; i < t.size(); i++) hashmap2[t[i] - 'a']++;

    for(int i = 0; i < 26; i++){
        if(hashmap1[i] != hashmap2[i]) return false;
    }
    return true;
}

int main(){
    // Given two strings s and t, check if they are anagrams of each other. Anagram of a word is another word made from rearranging its letters, using each letter exactly once. Both string contain letters from a to z lowercase only.
    string s = "anagram";
    string t = "nagaram";

    // Optimal Solution: O(s.size() + t.size()), O(1)
    // Keep two hashmaps, count frequency of each letter in both strings and just compare the hashmaps.
    // This could be made better by using single hashmap, incrementing at the index for string s and decrementing for string t, then checking if all elements in the hashmap are 0. But its not really a significant improvement as TC and SC will still be O(s.size() + t.size()) and O(26) -> O(1)
    cout<<(optimal(s, t) ? "True" : "False");

    cout<<"\n\n";
    return 0;
}