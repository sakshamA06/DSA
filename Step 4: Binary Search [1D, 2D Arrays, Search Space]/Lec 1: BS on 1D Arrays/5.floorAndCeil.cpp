#include<bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> arr, int x){
    int floor = -1;
    int ceil = -1;

    int low = 0;
    int high = arr.size()-1;
    while(low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
            high = mid-1;
            ceil = mid;
        }
        else{
            low = mid+1;
        }
    }
    if(ceil>=0)
    floor = arr[ceil] == x ? ceil : ceil-1;
    return {floor, ceil};
}

int main(){
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int x = 5;

    cout<<optimal(arr, x)[0]<<", "<<optimal(arr, x)[1];

    std::cout<<"\n\n";
    return 0;
}