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

ListNode* optimal(ListNode *head) {
    ListNode* temp = head;
    while(temp->next){
        if(temp->val == temp->next->val){
            ListNode* toDelete = temp->next;
            toDelete->prev->next = toDelete->next;
            if(toDelete->next) toDelete->next->prev = toDelete->prev;
            // if temp is at second last then toDelete will point to last node and toDelete->next will be null, so to avoid accessing null->prev, the if condition is necessary.
            delete toDelete;
        }
        else temp = temp->next;
    }
    return head;
}

int main(){
    // Given the head of a sorted doubly linked list, remove duplicate nodes present in the linked list and return the head.
    ListNode* head = dllFromArray( {1,1,1,2,3,3,4,5,5} );
    // your code below

    // Optimal Solution: O(n), O(1)
    // Just keep the first occurance and keep deleting the next node until its value isnt same as current's. It is crucial to not move on every iteration of the loop and hence keep the traversal inside else block. In the example above in which there are 3 duplicates then if we move after deleting just the 2nd node, we will move to the third 1, but we had to delete the third 1 as well, so only move when there are no duplicates or in other words when the current node's value isnt the same as the next one's.
    // You can also keep deleting duplicate nodes of the same value until there arent any left, and only then repair the list instead of deleting the duplicate and repairing for each one of the duplicate nodes. Might be slightly more optimised.
    ListNode* answer = optimal(head);

    // your code above
    ListNode* temp = answer;
    while(temp){
        cout<<temp->val;
        if(temp->next) cout<<" -> ";
        temp = temp->next;
    }
    cout<<"\n\n";
    return 0;
}