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

ListNode* optimal(ListNode* head, int k) {
    if(!head || !head->next) return head;
    int length = 1;
    ListNode* tail = head;
    while(tail->next){
        length++;
        tail = tail->next;
    }
    k = k%length;

    tail->next = head; // loop the list
    ListNode* temp = head;

    int count = length-k - 1; // to go to (length-k)th node, you move length-k-1 steps forward from head
    while(count--) temp = temp->next;

    tail = temp->next; // reusing instead of creating a new pointer. This is the new head.
    temp->next = nullptr; // temp is the new tail, so ending the list here
    return tail;
}

int main(){
    // Given the head of a linked list, rotate the list to the right by k places.
    ListNode* head = llFromArray( {1,2,3,4,5} );
    int k = 2;
    // your code below

    // Optimal Solution: O(2n), O(1)
    // Here's the flow:
    // 1->2->3->4->5 => calculate length = 5, tail->5, mod k => 1->2->3->4->5->1->2->... => temp moves forward 5-2-1 = 2 steps from head so => temp->3 => tail->4(i.e. temp->next) => 3->x => return tail => 4->5->1->2->3->x
    ListNode* answer = optimal(head, k);

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