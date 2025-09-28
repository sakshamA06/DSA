#include<bits/stdc++.h>
using namespace std;

string solution(string& s){
    vector<int> hashmap(128, 0);
    for(int i = 0; i < s.size(); i++){
        hashmap[s[i]]++;
    }

    auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(comp)>  pq(comp); // creating a priority queue sorted based on frequency which is second element of the pair

    for(int i = 0; i < hashmap.size(); i++){
        if(hashmap[i]) pq.push({i, hashmap[i]}); // char, freq
    }
    string ans = "";
    while(!pq.empty()){
        auto x = pq.top();
        ans.append(x.second, x.first);
        pq.pop();
    }
    return ans;
}

int main(){
    // Given a string of [a-z],[A-Z],[0-9], sort it according to the frequency of letters. Lowercase and uppercase are treated different. Return any one answer if there are multiple possible.
    string s = "tree"; // return bbaA or bbAa

    // Solution:
    // Count frequency in hashmap, store in priority queue for sorting, take out values from priority queue and append them their frequency number of times in answer string.
    cout<<solution(s);


    cout<<"\n\n";
    return 0;
}