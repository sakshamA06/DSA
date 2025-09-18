#include<bits/stdc++.h>
using namespace std;

bool possibleDistance(vector<int>& stations, int k, double dist){
    int newStations = 0;
    for(int i = 1; i < stations.size(); i++){
        int diff = stations[i]-stations[i-1];
        if(diff > dist){
            newStations += ceil(diff/dist) - 1;
        }
        if(newStations > k) return false;
    }
    return true;
}

double optimal(vector<int>& stations, int k){
    int diff = 0;
    for(int i = 1; i < stations.size(); i++){
        diff = max(diff, stations[i] - stations[i-1]);
    }
    double low = 0;
    double high = diff;
    while(high-low >= 1e-6){
        double mid = (low+high)/2;
        if(possibleDistance(stations, k, mid)) high = mid;
        else low = mid;
    }
    return high;
}

int main(){
    // Given an array of co-ordinates of gas stations and k more gas stations available, place these k stations such that the maximum distance between any two adjacent stations is minimized. Stations can be put at decimal co-ordinates. Return this minimum distance correct upto six decimal points.
    vector<int> stations = {3,6,12,19,33,44,67,72,89,95};
    int k = 2;

    // Other solutions to be written.
    
    // Optimal Solution: 
    // To be written.
    cout<<optimal(stations, k);

    std::cout<<"\n\n";
    return 0;
}