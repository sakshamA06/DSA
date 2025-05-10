#include<bits/stdc++.h>

void bf(std::vector<int>& arr){
    std::vector<int> pos;
    std::vector<int> neg;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else neg.push_back(arr[i]);
    }
    for(int i = 0; i < arr.size()/2; i++){
        arr[i*2] = pos[i];
        arr[i*2 + 1] = neg[i];
    }
}

void optimal(std::vector<int>& arr){
    std::vector<int> result(arr.size(), 0);
    int pos = 0, neg = 1;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0){
            result[pos] = arr[i];
            pos += 2;
        }
        else{
            result[neg] = arr[i];
            neg += 2;
        }
    }

    // only cuz i dont wanna return a vector for consistency, shouldnt be counted towards TC
    for(int i = 0; i < arr.size(); i++){
        arr[i] = result[i];
    }
}

void variety2(std::vector<int>& arr){
    std::vector<int> pos;
    std::vector<int> neg;
    int pn = 0, nn = 0; // n for +ve is pn, n for -ve is nn
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0){ pos.push_back(arr[i]); pn++;}
        else{ neg.push_back(arr[i]); nn++;}
    }
    int min = pn < nn ? pn : nn;
    for(int i = 0; i < min; i++){
        arr[i*2] = pos[i];
        arr[i*2 + 1] = neg[i];
        pn--; nn--;
    }
    for(int i = min*2; pn--; i++){
        arr[i] = pos[i - min*2 + min];
    }
    for(int i = min*2; nn--; i++){
        arr[i] = neg[i - min*2 + min];
    }

}

int main(){
    // Given an array of equal number of positive and negative numbers, rearrange them so that their order remains unchanged but they alternate in sign with positive being first.
    // Eg - {-1, 2, -2, 4} would become {2, -1, 4, -2}
    // Variety 2 of this problem is that they might not be equal in number, and if so then put the remaining in the back without changing order
    std::vector<int> arr = {3, 1, -2, -5, 6, 1, -2, -4};

    // Brute Force: O(2n) , O(n)
    // Iterate through and store all positive elements in one array, and all negative elements in another.
    // Then re-iterate and overwrite the positive elements at indices 0, 2, 4, etc and negative elements at indices 1, 3, 5, etc
    // bf(arr);

    // Optimal Solution: O(n) , O(n)
    // Make a new array of the same size. Make two pointers pos and neg pointing to 0 and 1 initially, these represent the position the next respective number will fill.
    // Iterate through and if you encounter a positive, put it at pos, increment it by 2 and same for neg.
    // So positive elements get filled at 0, 2, 4, etc and negative at 1, 3, etc.
    optimal(arr);

    // Variety 2:
    // TC - O(n) + O(max(pn, nn)) where pn and nn are frequencies of +ve and -ve numbers respectively. So worst case is O(2n) when array has only +ve or only -ve numbers.
    // SC - O(n) for same reason as brute force i.e. pn + nn = n
    // Fall back to brute force solution, and just add the remaining of whichever of +ve/-ve are left in the end.
    // variety2(arr);

    for(auto it:arr){
        std::cout<<it<<" ";
    }

    std::cout<<"\n\n";
    return 0;
}