#include<bits/stdc++.h>
using namespace std;

bool possibleDistribution(vector<int> books, int m, int p){
    int students = 1;
    int accPages = 0;
    for(int i = 0; i < books.size(); i++){
        accPages += books[i];
        if(accPages > p){
            students++;
            accPages = books[i];
        }
        if(students > m) return false;
    }
    return true;
}

int optimal(vector<int> books, int m){
    if(m>books.size()) return -1;
    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    while(low <= high){
        int mid = low + (high-low)/2;
        if(possibleDistribution(books, m, mid)) high = mid-1;
        else low = mid+1;
    }
    return low;
}

int main(){
    // Given an array of books where books[i] is the number of pages of i-th book and m students, allocate books to students such that maximum number of pages any one gets is minimum. Return this minimum number of pages.
    vector<int> books = {25, 46, 28, 49, 24};
    int m = 4;

    // Brute Force: O(n + n*(ans-max)) , O(1)
    // Same concept from previous problems, the only thing slightly changing in these problems is the helper function that checks if an answer is possible or not.
    // Just go from max to sum and return the first answer that works.

    // Optimal Solution: O(n + n*log(sum-max)) , O(1)
    // In this case, we actually have answers like {0,0,0,1,1,1,1,0,0,0,0}, cuz of the restriction that every student must get atleast one book, if we set the number of pages too high, then last students wont get any books but we still return that as a possible answer because we need to find the minimum and move left so we convert that answer array to (0,0,0,1,1,1,1,(1,1,1,1))
    // Other things are the same.

    cout<<optimal(books, m);

    std::cout<<"\n\n";
    return 0;
}