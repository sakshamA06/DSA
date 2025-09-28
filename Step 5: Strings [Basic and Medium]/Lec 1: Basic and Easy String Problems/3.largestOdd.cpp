#include<bits/stdc++.h>
using namespace std;

string optimal(string& num) {
    int rightMostOdd = -1;
    for(int i = num.size()-1; i >= 0; i--){
        // if(num[i] == '1' || num[i] == '3' || num[i] == '5' || num[i] == '7' || num[i] == '9'){
        //     rightMostOdd = i;
        //     break;
        // }
        // OR the much shorter
        if((num[i]-'0') %2 != 0){
            rightMostOdd = i;
            break;
        }
    }
    // string res = "";
    // for(int i = 0; i <= rightMostOdd; i++){
    //     res += num[i];
    // }
    // return res; // without modifying original string
    num.resize(rightMostOdd+1);
    return num; // without using extra space
}

int main(){
    // Given a string representing a large integer, return the largest odd number that is a substring of it.
    string num = "354274"; // return 35427

    // Brute Force: O(n^2), O(1)
    // Generate all substrings and keep track of max, but falls apart when number is stupendously large like 1000 digits.

    // Optimal Solution: O(n), O(1)
    // Space complexity will be O(n) if you can't modify the string
    // Check from the back for the first odd digit, once found, the number from start to this digit is largest odd number.
    cout<<optimal(num)<<endl;

    cout<<"\n\n";
    return 0;
}