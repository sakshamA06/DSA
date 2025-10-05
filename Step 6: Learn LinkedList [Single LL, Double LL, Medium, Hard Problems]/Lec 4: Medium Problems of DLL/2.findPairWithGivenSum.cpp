#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

ListNode* dllFromArray(vector<int> arr){
    if(arr.size() == 0) return nullptr;
    ListNode* dummyHead = new ListNode(0);
    ListNode* temp = dummyHead;
    for(int i = 0; i < arr.size(); i++){
        temp->next = new ListNode(arr[i], nullptr, temp);
        temp = temp->next;
    }
    temp = dummyHead->next;
    temp->prev = nullptr;
    delete dummyHead;
    return temp;
}

vector<pair<int, int>> optimal(ListNode* head, int target){
    vector<pair<int, int>> indices;
    ListNode* left = head;
    ListNode* right = head;
    while(right->next) right = right->next;
    while(left && right && left->val < right->val){
        int sum = left->val + right->val;
        if(sum > target){
            right = right->prev;
        }
        else if(sum < target){
            left = left->next;
        }
        else{
            indices.push_back({left->val, right->val});
            left = left->next;
            right = right->prev;
        }
    }
    return indices;
}

int main(){
    // Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.
    ListNode* head = dllFromArray( {1,2,3,4} );
    int target = 5;
    // your code below

    // Optimal Solution: O(2n), O(1)
    // SC: The vector of pairs is only used to return the answer, so its not counted towards SC.
    // Two pointer approach, get the right to the end, and then keep checking the sum and moving the pointers accordingly. We can't know if left pointer is left of right, but the list is sorted so their values give the clue, but if left or right are nullptr then checking their values will result in a null dereference exception so we check if they both are still within the dll first. 
    vector<pair<int, int>> answer = optimal(head, target);

    // your code above
    for(auto& x : answer){
        cout<<"("<<x.first<<", "<<x.second<<") ";
    }

    cout<<"\n\n";
    return 0;
}