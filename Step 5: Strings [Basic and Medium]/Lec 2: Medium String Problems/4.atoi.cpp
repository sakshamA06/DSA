#include<bits/stdc++.h>
using namespace std;

int myAtoi(string& s){
    long long num = 0;
    // for(int i = 0; i < s.size(); i++){
    //     if(s[i])
    // }
    int i = 0;
    int sign = 1;
    while(s[i] == ' ') i++; // skip leading spaces
    // deal with sign
    if(s[i] == '-'){
        sign = -1;
        i++;
    }
    else if(s[i] == '+') i++;

    // convert the string to number
    while(i < s.size()){
        if(s[i] < '0' || s[i] > '9') return sign*num; // any non-digit results in stopping the reading and returning the value so far accumulated
        else{
            num = (num*10) + (s[i]-'0');
            // handle overflow
            if((long long)sign*num > INT_MAX) return INT_MAX;
            if((long long)sign*num < INT_MIN) return INT_MIN;
        }
        i++;
    }
    return sign*num;
}

int main(){
    // Given a string, convert it into a number.
    string s = "131535321353213"; // should return -1337

    // Optimal Solution: O(n), O(1)
    // Everything is explained in the function itself.
    cout<<myAtoi(s);

    cout<<"\n\n";
    return 0;
}