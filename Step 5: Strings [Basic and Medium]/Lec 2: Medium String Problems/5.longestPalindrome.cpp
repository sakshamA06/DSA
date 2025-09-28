#include<bits/stdc++.h>
using namespace std;

string better1(string& s){
    int n = s.size();
    int longest = 0;
    int bestLeft = -1;
    for(int i = 0; i < n; i++){
        int left = i;
        int right = i;
        while(left >= 0 && right < n && s[left] == s[right]){
            left--; right++;
        }
        if(right-left-1 > longest){
            longest = right-left-1;
            bestLeft = left+1;
        }
    }
    for(int i = 0; i < n-1; i++){
        int left = i;
        int right = i+1;
        while(left >= 0 && right < n && s[left] == s[right]){
            left--; right++;
        }
        if(right-left-1 > longest){
            longest = right-left-1;
            bestLeft = left+1;
        }
    }
    return s.substr(bestLeft, longest);
}

string better2(string& s){
    int n = s.size();
    int longest = 0;
    int bestLeft = -1;
    for(int i = 0; i < n;){
        int left = i;
        int right = i;
        while(right < n-1 && s[right] == s[right+1]) right++;
        i = right + 1;
        while(left >= 1 && right < n-1 && s[left-1] == s[right+1]){
            left--; right++; // after this left and right point inclusively to the boundaries of current palindrom
        }
        if(right - left + 1 > longest){
            longest = right - left + 1;
            bestLeft = left;
        }
        if (n-i <= longest/2) break; // i is the center, if the center has moved so far to the right that number of elements to its right(n-i) is lesser than half of longest palindrome then we can never find a longer palindrome by considering any of the elements to the right, so just break out and early at this point.
    }
    return s.substr(bestLeft, longest);
}

int main(){
    // Given a string s, return the longest palindromic substring in s.
    string s = "cbbd";

    // Brute Force: O(n^3), O(n)
    // Generate all substrings and check which ones are palindromes, and then keep track of largest.

    // Better Solution: O(n^2), O(1)
    // Iterate through the string, considering each index as the center of a potential palindrome. Then two centers at once for even length palindromes. Expand outwards on both side, keep checking if a larger palindrome can be made, keep track of left pointer whenever you encounter a larger palindrome along with its length. Finally return the substring. Its better to store indices and return a substring in the end rather than building the entire palindrome as strin concatenation is a heavy operation.
    // cout<<better1(s);

    // You can save two search for odd length and even length palindromes by first calculating longest series of duplicates and then simply expand outwards from there.
    cout<<better2(s);

    // Optimal Solution: O(n)
    // Manacher's algo, havent studied.

    cout<<"\n\n";
    return 0;
}