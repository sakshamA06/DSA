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

ListNode* bf(ListNode* head){
    if(head->next == nullptr) return head;
    int count = 1;
    ListNode* temp = head;
    while(temp->next){
        temp = temp->next;
        count++;
    }
    int middle = (count/2) + 1;
    temp = head;
    count = 1;
    while(count != middle){
        temp = temp->next;
        count++;
    }
    return temp;
}

ListNode* mySol(ListNode* head){
    ListNode* temp = head;
    ListNode* middle = temp;
    int count = 0;
    while(temp->next){
        temp = temp->next;
        count++;
        if(count%2) middle = middle->next;
    }
    return middle;
}

ListNode* optimal(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next) // or while(fast != null && fast->next != null)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    // Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.
    ListNode* head = llFromArray( {1,2,3,4,5,6} ); // return the '3' node if its till 6 or '4' if its till 5.
    // 1->2->3->4->5->6->x
    // your code below

    // Brute Force: O(n + n/2), O(1)
    // Get the length, calulate the 1-based index of the node, traverse again to go to it and return it.
    // ListNode* answer = bf(head);

    // My Solution: O(n), O(1)
    // While traversing always update a pointer to middle node of the list from start to current node. As it happens, the middle node pointer only moves forward when current node pointer encounters an odd index(0-based) or even index(1-based). Just move it when it does, and return it at the end.
    // ListNode* answer = mySol(head);

    // Optimal Solution: O(n/2), O(1)
    // Tortoise and hare algorithm:
    // Keep a fast pointer and a slow pointer. The fast pointer moves two steps at a time and slow one moves one at a time. We continue until fast can move forward, that is when fast is not null(this check is necessary in case fast was at second last and it moved two places, so it points to null now, checking fast->next directly would lead to errors) and fast->next is not null(i.e. fast->next->next exists). The slow pointer will always end up pointing to the middle element due to obvious reasons.
    ListNode* answer = optimal(head);

    // your code above
    ListNode* temp = head;
    while(temp){
        cout<<temp->val;
        if(temp->next) cout<<" -> ";
        temp = temp->next;
    }
    cout<<"\nMiddle node: "<<answer->val;

    cout<<"\n\n";
    return 0;
}