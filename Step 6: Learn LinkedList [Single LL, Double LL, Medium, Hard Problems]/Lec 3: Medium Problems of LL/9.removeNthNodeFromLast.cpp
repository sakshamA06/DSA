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

ListNode* optimal(ListNode* head, int n){
    if(!head->next) return nullptr;
    ListNode* vanguard = head;
    ListNode* temp = head;
    for(int i = 0; i < n; i++){
        vanguard = vanguard->next;
    }
    if(!vanguard){
        head = head->next;
        delete temp;
        return head;
    }
    ListNode* rearguard = head;
    while(vanguard->next){
        rearguard = rearguard->next;
        vanguard = vanguard->next;
    }
    temp = rearguard->next;
    rearguard->next = temp->next;
    delete temp;
    return head;
    return head;
}

int main(){
    // Given the head of a linked list, remove the nth node from the end of the list and return its head.
    ListNode* head = llFromArray( {1,2,3,4,5} );
    // your code below

    // Brute Force: O(2*length), O(1)
    // Traverse the array to find the length, then find the index of the node before the node to delete which is just length - n, then delete the next node cleanly. If length and n are equal then we have to delete head, so store head in temp, move head forward, delete temp and return head.

    // Optimal Solution: O(length), O(1)
    // Keep a vanguard variable that will be n nodes ahead of rearguard(the node before the node to delete). Then if vanguard crosses the list that means it is length amount of nodes ahead, which in turn means length is n. So follow deleting the head procedure, otherwise delete the node after rearguard.
    ListNode* answer = optimal(head, 2);

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