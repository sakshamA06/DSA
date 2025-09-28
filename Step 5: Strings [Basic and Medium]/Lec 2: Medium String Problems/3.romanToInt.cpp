#include<bits/stdc++.h>
using namespace std;

int value(char c){
    switch(c){
        case 'I':
        return 1;
        case 'V':
        return 5;
        case 'X':
        return 10;
        case 'L':
        return 50;
        case 'C':
        return 100;
        case 'D':
        return 500;
        case 'M':
        return 1000;
        default:
        return 0;
    }
}

int optimal(string& s){
    int n = s.size();
    int prev = value(s[n-1]);
    int sum = prev;
    for(int i = n-2; i >= 0; i--){
        int val = value(s[i]);
        if(val >= prev) sum += val;
        else sum -= val;
        prev = val;
    }
    return sum;
}

int main(){
    // Convert roman numerals to number.
    string s = "MCMXCIV";

    // Optimal Solution: O(n), O(1)
    // Iterate from the back, and if any character is greater than or equal to its previous one then add it otherwise subtract it.
    cout<<optimal(s);

    cout<<"\n\n";
    return 0;
}