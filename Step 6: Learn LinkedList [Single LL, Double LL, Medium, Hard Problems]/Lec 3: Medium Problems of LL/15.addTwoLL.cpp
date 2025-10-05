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

ListNode* optimal(ListNode* l1, ListNode* l2){
    ListNode* dummyNode = new ListNode(0);
    ListNode* temp = dummyNode;
    int carry = 0;
    int first = 0;
    int second = 0;
    while(l1 || l2 || carry){
        temp->next = new ListNode(0);
        temp = temp->next;

        first = (l1 ? l1->val : 0);
        second = (l2 ? l2->val : 0);

        temp->val = first + second + carry;
        carry = temp->val/10; // get the tens digit
        temp->val %= 10; // get the ones digit

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    // if(carry) temp->next = new ListNode(carry); // either this or the more cleaner above {|| carry}.

    temp = dummyNode->next;
    delete dummyNode;
    return temp;
}

int main(){
    // Given two non-empty linked lists(of length m and n) representing two non-negative integers, the digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    ListNode* head1 = llFromArray( {2,4,3,1} ); // 2->4->3->x => 1342
    ListNode* head2 = llFromArray( {5,6,4} ); // 5->6->4->x => 465
    // 1342 + 465 = 1807 => return 7->0->8->1->x
    // your code below

    // Optimal Solution: O(max(m, n)), O(max(m, n))
    // Just keep a new ll and append digit nodes to it one by one. This is a pretty simple implementation. Only edge case is when answer is longer than both lists, so we have to append a new carry node at the end. You could add an if block after the loop to check for a carry and add the node or simply dont let the loop end when you have a carry left by adding a {|| carry} to its condition.
    ListNode* answer = optimal(head1, head2);

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