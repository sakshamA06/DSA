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

bool bf(ListNode* head){
    stack<int> st;
    ListNode* temp = head;
    int length = 0;
    while(temp){
        temp = temp->next;
        length++;
    }
    temp = head;
    for(int i = 0; i < length/2; i++){
        st.push(temp->val);
        temp = temp->next;
    }
    if(length%2) temp = temp->next;
    while(temp){
        if(temp->val != st.top()) return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}

bool optimal(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow stores the middle node
    ListNode* prev = nullptr;
    ListNode* curr = slow;
    while(curr){
        ListNode* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    // now second half is reversed and prev stores the first node of second half
    ListNode* left = head;
    ListNode* right = prev;
    bool pal = true;
    // comparing both halves
    while(right){
        if(left->val != right->val){
            pal = false;
            break;
        }
        left = left->next;
        right = right->next;
    }
    // reverse second half again so that og linked list remains unchanged
    curr = prev;
    prev = nullptr;
    while(curr){
        ListNode* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return pal;
}

int main(){
    // Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
    ListNode* head = llFromArray( {1,2,3,3,2,1} );
    // 1->2->3->3->2->1->x
    // your code below

    // Brute Force: O(2n), O(n/2)
    // Find the length of the list. Now re-traverse and until half the list, keep pushing the value onto a stack, after that if length was odd then skip the next node(middle node), otherwise move on to the next part.
    // Now stack has half the list, now go through the rest checking each node's value again top of stack and popping, effectively checking the values in reverse order. If it ever doesnt match return false otherwise return true.

    // Optimal Solution: O(n), O(1)
    // Find the middle node using tortoise and hare algorithm, reverse either one of the halves, compare it with the other half. Finally reverse the half again that was reversed before so that there's no change in the actual linked list.
    bool answer = optimal(head);

    // your code above
    cout<<(answer ? "Palindrome." : "Not a palindrome.");

    cout<<"\n\n";
    return 0;
}