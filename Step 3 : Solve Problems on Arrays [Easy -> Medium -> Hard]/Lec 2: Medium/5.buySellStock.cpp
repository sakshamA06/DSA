#include<bits/stdc++.h>

std::pair<int, int> bf(std::vector<int> arr){
    int profit = -1;
    int maxprofit = -1;
    int buyday = -1, sellday = -1;
    for(int i = 0; i < arr.size(); i++){
        for(int j = i+1; j < arr.size(); j++){
            profit = arr[j] - arr[i];
            if(profit > maxprofit){
                maxprofit = profit;
                buyday = i;
                sellday = j;
            }
        }
    }
    return {buyday, sellday};
}

std::pair<int, int> optimal(std::vector<int> arr){
    int profit = 0;
    int maxprofit = 0;
    int buyday = -1, sellday = -1;
    int mini = 0; // stores the index of minimum element till now
    for(int i = 1; i < arr.size(); i++){
        profit = arr[i] - arr[mini];
        if(profit > maxprofit){
            maxprofit = profit;
            buyday = mini;
            sellday = i;
        }
        if(arr[i] < arr[mini]) mini = i;
    }
    return {buyday, sellday};
}

int main(){
    // Given an array of stock prices across several days, find the best day to buy and sell for maximum profit. You can buy and sell only once. Actual question asked for maximum profit but thats easier.
    std::vector<int> arr = {7, 1, 5, 3, 6, 4};

    // Brute Force: O(n^2) , O(1)
    // Pick a day and iterate through entire array to find max profit that can be made by buying on that day, and update the maxprofit, buy day and sell day when u find one, and repeat with every other day.
    // Make sure to iterate the second loop after the picked day, cuz u can only sell after buying.
    // std::pair<int, int> result = bf(arr);

    // Optimal Solution: O(n) , O(1)
    // Instead of picking a buy day first then finding the sell day, if we select a sell day first, then we can do everything in one pass only.
    // Select second day as sell day, then buy day must be the day before it.
    // Then select third day as sell day, and then buy day is the minimum between first two days, the key is to keep doing min between last two days so that you don't have to run an entire separate loop to find the minimum.
    // Only update the sellday buyday variable when u find a better profit
    std::pair<int, int> result = optimal(arr);

    std::cout<<result.first<<", "<<result.second;

    std::cout<<"\n\n";
    return 0;
}
