#include<bits/stdc++.h>
using namespace std;

bool optimal(string& s, string& t){
    int n = s.size();
    int m1[256] = {0}; // All the values in the array will be implicitly set to 0
    int m2[256] = {0};

    for(int i = 0; i < n; i++){
        if(m1[s[i]] != m2[t[i]]) return false;

        m1[s[i]] = i+1; // cant set to i as for the first iteration its value will be 0 and the array is initialized with 0
        m2[t[i]] = i+1;
    }
    return true;

}

int main(){
    // Given two strings, return whether they are isomorphic or not.
    // Two strings s and t are isomorphic if the characters in s can be replaced to get t. With one to one mappings.
    // egg and add, e->a, g->d, so isomorphic
    // foo and bar, f->b, o->a, o->r but 'o' already mapped to 'a' so not isomorphic
    string s = "foo";
    string t = "bar";

    // Optimal solution: O(n), O(1)
    // Take two arrays(hash maps) which will track which letter appeared where in both the strings.
    // We update the s[i] index of m1 with the i+1, so that next time we encounter this letter we can know at which place it occured in first string and whether whatever it was paired with at the time occured in second string or not.
    // Say foo and bar are the strings.
    // First m1[f] = 1 and m2[b] = 1, the exact index doesnt matter whether its 0-based, 1-based or 100-based.(call it occurance index)
    // Next we get m1[o] = 2 and m2[a] = 2
    // Now for the third letter of each, m1[o] will be updated to 3 but m2[r] is 0.
    // We are also checking each time if this occurance index of letters from both the string is same or not. So in the third iteration when we check if m1[o](i.e. 2) is equal to m2[r](i.e. 0), we know the pairing is off (actually the m1[o] wont get updated to 2 like the above line said.)
    // This method basically tracks appearances and repetitions.
    cout<<(optimal(s, t) ? "Isomorphic" : "Not Isomorphic");

    cout<<"\n\n";
    return 0;
}