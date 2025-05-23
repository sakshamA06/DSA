#include<bits/stdc++.h>
using namespace std;

vector<int> bf(vector<int> arr){
    int missing = -1;
    int repeating = -1;
    int n = arr.size();
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == i) count++;
        }
        if(count == 2) repeating = i;
        else if(count == 0) missing = i;
        if(missing != -1 && repeating != -1) break; // break out when both are found
    }
    return vector<int> {missing, repeating};
}

vector<int> better(vector<int> arr){
    int missing = -1;
    int repeating = -1;
    int n = arr.size();
    vector<int> hash(n+1, 0);
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }
    for(int i = 1; i < n+1; i++){
        if(hash[i] == 0) missing = i;
        else if(hash[i] == 2) repeating = i;
        if(missing != -1 && repeating != -1) break;
    }
    return vector<int> {missing, repeating};
}

vector<int> optimalMath(vector<int> arr){
    long long n = arr.size();
    long long S = 0;
    long long S2 = 0;
    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*(2*n+1))/6;
    for(int i = 0; i < n; i++){
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    long long d = S-Sn; // equal to repeating - missing
    long long sd = S2-S2n; // equal to repeating^2 - missing^2
    long long missing = (sd-(d*d))/(2*d);
    long long repeating = (sd+(d*d))/(2*d);
    return vector<int> {(int)missing, (int)repeating};
}

vector<int> optimalXOR(vector<int> arr){
    int n = arr.size();
    int xr = 0;
    int diffBit = 0;
    for(int i = 0; i < n; i++){
        xr ^= arr[i] ^ (i+1);
    }
    // diffBit can be calculated without a loop like diffBit = xr & ~(xr-1) but this following loop is more intuitive so i will keep it, but not count it for TC analysis.
    for(int i = 0; (1<<i) <= xr; i++){
        if(xr & (1<<i)){
            diffBit = i;
            break;
        }
    }
    int first = 0;
    int second = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] & (1<<diffBit)) first ^= arr[i];
        else second ^= arr[i];
        if((i+1) & (1<<diffBit)) first ^= (i+1);
        else second ^= (i+1);
    }
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == first) cnt++;
    }
    if (cnt == 0) return {first, second};
    return {second, first};
    // returned as {missing, repeating}
}

int main(){
    // Given an array containing numbers from 1 to n, where one number is missing and one is repeated twice so that the size remains n, return them.
    vector<int> arr = {4,3,6,2,5,5};

    // Brute Force: O(n^2) , O(1)
    // Iterate through the entire array checking for number from 1 to n, and store them in repeating/missing number depending on their count.
    // vector<int> res = bf(arr);

    // Better Solution: O(2n) , O(n)
    // Keep a hash array and iterate through it to find out repeating and missing numbers.
    // vector<int> res = better(arr);
    
    // Optimal Solution: O(n) , O(1)
    // Method 1: Maths
    // Let S be sum of array and Sn be sum of first n natural numbers, also size of array is n
    // S - Sn = repeating - missing
    // Now let S2 be sum of squares of elements of array, and S2n be sum of squares of first n natural numbers
    // S2 - S2n = repeating^2 - missing^2 = r^2 - m^2 = (r+m)(r-m) = (r+m)(S-Sn)
    // so S2 - S2n / S - Sn = r+m;
    // we know r+m and r-m so figuring out r and m is easy
    // vector<int> res = optimalMath(arr);

    // Method 2: XOR : O(3n) , O(1)
    // First we xor the entire array and the numbers 1->n, which in the end will give missing^repeating or xr = m^r
    // Elements means elements of array and numbers means all the natural numbers from 1 to n
    // Now we find the first 1 from the right in xr, this 1 signifies the first bit from right which is different in m from r, this will always be present as for m and r to be different, they have to be different at atleast one bit, stored by diffBit variable.
    // Now we will group the elements and numbers based on this bit, since besides m,r each element will appear exactly twice between elements and numbers, and since these are duplicates they will be grouped in the same grp(acc to diffBit). Whichever group the r goes, it will appear thrice, and m will appear once in its grp, every other number will be present twice in its grp. Now we will xor the entire grps separately, one group will have r leftover since it was present thrice and every other element got cancelled by itself, same will happen with m.
    // So now the two groups contain m or r, we dont know which but they are guaranteed to be m and r. Also remember m and r can never be in the same group cuz the grps were made based on diffBit, the bit that differentiated m and r.
    // Now just loop through the array to check if one of the number is missing, if it is then other is repeating, if not then the opposite is true.
    vector<int> res = optimalXOR(arr);
    

    cout<<"Missing -> "<<res[0];
    cout<<"\nRepeating -> "<<res[1];

    std::cout<<"\n\n";
    return 0;
}