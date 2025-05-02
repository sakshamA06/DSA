#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool check(vector<int>& nums) {
            int max = nums[0];
            for(int i = 0; i < nums.size(); i++){
                if (nums[i] > max) max = nums[i];
            }
            for(int i = 0; i < nums.size()-1; i++){
                if((nums[i] == max && nums[i] < nums[i+1]) || (nums[i] != max && nums[i] > nums[i+1])) return false;
            }
            return true;
        }
    };

int main(){
    Solution sol;
    vector<int> nums = {3,5,4,1,2};
    cout<<sol.check(nums);

    std::cout<<"\n\n";
    return 0;
}