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
    ListNode* prev = nullptr;
    while(temp){
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

int main(){
    // Given the head of a singly linked list, reverse the list, and return the reversed list.
    ListNode* head = llFromArray( {1,2,3,4,5,6} );
    // 1->2->3->4->5->6->x
    // your code below

    // Brute Force: O(2n), O(n)
    // Go through the list, push data of each node in a stack, traverse it again while replacing the data in the nodes with popped out data from stack.
    // So first node will get data of last, second will get second last's and so one.

    // Optimal Solution: O(n), O(1)
    // Keep a pointer to previous node, and next node, and keep updating each node's next pointer to the previous node.
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