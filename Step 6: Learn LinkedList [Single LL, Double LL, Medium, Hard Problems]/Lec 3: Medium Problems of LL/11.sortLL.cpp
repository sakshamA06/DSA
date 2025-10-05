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

ListNode* findMiddle(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* mergeList(ListNode* head1, ListNode* head2){
    ListNode dummyNode(-1);
    ListNode* temp = &dummyNode;
    while(head1 && head2){
        if(head1->val <= head2->val){
            temp->next = new ListNode(head1->val);
            head1 = head1->next;
        }
        else {
            temp->next = new ListNode(head2->val);
            head2 = head2->next;
        }
        temp = temp->next;
    }
    temp->next = (head1 ? head1 : head2);
    return dummyNode.next;
}
ListNode* optimal(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* middle = findMiddle(head);
    ListNode* leftHead = head;
    ListNode* rightHead = middle->next;
    middle->next = nullptr;
    leftHead = optimal(leftHead);
    rightHead = optimal(rightHead);
    return mergeList(leftHead, rightHead);
}

int main(){
    // Given the head of a linked list, return the list after sorting it in ascending order.
    ListNode* head = llFromArray( {4,2,1,3} );
    // your code below

    // Brute Force: O(2n + n log n), O(n)
    // Store the list in an array, sort the array, copy back all the data

    // Optimal Solution: O(n log n), O(1)
    // Basically merge sort on linked lists. Find the middle using tortoise and hare but you need the first middle out of two if length is even so slightly modify it by fast = fast->next. Then normal split. Then sort both halves. For merging back, if you assign nodes instead of values to the temp ll, you dont need to traverse in the end when one of the two halves of ll is finished, you can directly assign the node and rest will be linked as well since its a linked list afterall.
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