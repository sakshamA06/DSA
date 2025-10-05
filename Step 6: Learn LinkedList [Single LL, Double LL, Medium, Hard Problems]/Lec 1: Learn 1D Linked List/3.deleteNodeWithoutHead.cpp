#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void bf(ListNode* node) {
    while(node->next->next){
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    delete node->next;
    node->next = NULL;
}

void optimal(ListNode* node) {
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = node->next->next;
    delete temp;
}

int main(){
    // Given a singly LL and a node from it, remove it from the linked list. The head is not given and removing doesn't necessarily mean deleting that node from memory. It should just have the effect of deletion on the linked list.
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9); // given LL
    ListNode* node = head->next; // given node to delete
    // your code below

    // Brute Force: O(n), O(1)
    // Shift every node's data to left by one from the node and delete the last one
    // bf(node);

    // Optimal Solution: O(1), O(1)
    // Instead of copying every element, do it just for the first and then change the next pointer to point two nodes ahead, effectively skipping the node from which the value was copied back to your current node, and delete that skipped node.
    optimal(node);

    // your code above
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }

    cout<<"\n\n";
    return 0;
}