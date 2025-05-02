#include<bits/stdc++.h>

int main(){
    // Given an array of unique n-1 positive integers from 1 to n, return the missing number.
    int n = 9;
    int arr[n-1] = {1, 4, 2, 5, 9, 8, 3, 6};
    int missing_number = -1;
    // Brute Force: O(n^2) , O(1)
    // Loop through 1 to n and search each number in the array
    // for(int i = 1; i <= n; i++){
    //     bool found = false;
    //     for(int j = 0; j < n-1 && !found; j++){
    //         if(arr[j] == i) found = true;
    //     }
    //     if(!found){
    //         missing_number = i;
    //         break;
    //     }
    // }

    // Better Solution: O(n) , O(1)
    // Add all the numbers in the array and subtract from total sum of 1 to n.
    // The sum of array will be almost equal but the missing number is not added so the difference between them will be the missing number.
    // int sum = 0;
    // for(int i = 0; i < n-1; i++){
    //     sum += arr[i];
    // }
    // missing_number = ((n*(n+1))/2) - sum; // sum of first n numbers = ((n*(n+1))/2)

    // Optimal Solution: O(n) , O(1)
    // Bitwise XOR of any two numbers is 0 if they are same
    // Bitwise XOR of any number with 0 is that number itself
    // Let the missing number be m, if we do then except for that number every number in the array will match with one number from 1 to n:
    // let arr = 1, 2, 3, 5 ; m = 4
    // XOR-ing them with 1, 2, 3, 4, 5 and we get (1^1) ^ (2^2) ^ (3^3) ^ 4 ^ (5^5)
    // Each XOR in brackets will be 0 and their xor with m will be m

    missing_number = 0;
    for(int i=0; i < n-1; i++){
        missing_number ^= arr[i] ^ (i+1);
    }
    missing_number ^= n;
    std::cout<<"Missing number is "<<missing_number;

    std::cout<<"\n\n";
    return 0;
}