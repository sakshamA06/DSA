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
ListNode* mySol(ListNode* head){
    if(!head || !head->next || !head->next->next) return head;
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    ListNode* oddTail = p1;
    ListNode* evenHead = p2;
    bool saveOdd = true;
    while(p2){
        p1->next = p2->next;
        p1 = p2;
        if(saveOdd) oddTail = p1; // alternates
        saveOdd = !saveOdd;
        p2 = p2->next;
    }
    oddTail->next = evenHead;

    return head;
}

ListNode* optimal(ListNode* head) {
    if(!head || !head->next || !head->next->next) return head;
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = head->next;
    while(even && even->next){
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;

    return head;
}

int main(){
    // Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
    ListNode* head = llFromArray( {1,2,3,4,5} );
    // your code below

    // Brute Force: O(2n), O(n)
    // Store all odd indexed data, then even indexed data in order in an array and then re-traverse the ll and overwrite the data from the array.

    // My Solution: O(n), O(1)
    // Save the head of even ll and then basically update the current node's next to skip one node by setting it to next of its next node, and then reposition both nodes so that we are in the same situation as before where we have to change the current node's next to skip one. Keep track of odd nodes by alternately updating oddTail, and finally connect tail of odd indexed ll to head of even indexed ll.
    // ListNode* answer = mySol(head);

    // Optimal Solution: O(n/2), O(1)
    // Keep odd and even node pointers, store starting even node separately and make them skip their next node so every odd node skips even ones and even skips odd ones. Even will always be ahead of odd so do this until even reaches the last node or nullptr. Finally odd will always point to last odd node, no matter ll size is odd or even. So stitch the two disjoint lists by setting odd's next to starting even node.
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