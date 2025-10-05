#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* llFromArray(vector<int> arr){
    if(arr.size() == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1; i < arr.size(); i++){
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

ListNode* optimal(ListNode* head){
    if(!head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head->next->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return head;
}

int main(){
    // You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
    ListNode* head = llFromArray( {1,2,3,4,5} );
    // your code below

    // Brute Force: O(2n), O(1)
    // Get the length, calulate the 1-based index of the node to delete, traverse again to go to the node before it and delete it.

    // Optimal Solution: O(n), O(1)
    // Its similar to finding the middle node, except for deleting we need to get the node before middle node. So simply give the fast node a headstart in the tortoise and hare algorithm.
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