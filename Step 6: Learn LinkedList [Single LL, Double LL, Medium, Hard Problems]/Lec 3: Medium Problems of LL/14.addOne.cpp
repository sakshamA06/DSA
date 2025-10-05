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
    ListNode* temp = head;
    ListNode* dummyNode = new ListNode(0, head);
    ListNode* carry = dummyNode; // carry stores the node to increase by one
    while(temp){
        if(temp->val != 9) carry = temp;
        temp = temp->next;
    }
    carry->val++; // add one
    carry = carry->next;
    while(carry){
        carry->val = 0; // turn following 9s to 0s
        carry = carry->next;
    }
    if(dummyNode->val) return dummyNode;
    delete dummyNode;
    return head;
}

int main(){
    // Given the head of a linked list of integer data nodes representing a number, add one to the number formed by the ll and return the ll in the same format.
    ListNode* head = llFromArray( {9,9,9} );
    // 9->9->9->x => return 1->0->0->0->x
    // your code below

    // Optimal Solution: O(2n), O(1)
    // Find the first non-9, since that will stop the carry propagation. If none exists, then we need an extra node with 1 to connect to head. Now convert all 9s to 0s.
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