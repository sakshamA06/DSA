#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

ListNode* dllFromArray(vector<int> arr){
    if(arr.size() == 0) return nullptr;
    ListNode* dummyHead = new ListNode(0);
    ListNode* temp = dummyHead;
    for(int i = 0; i < arr.size(); i++){
        temp->next = new ListNode(arr[i], nullptr, temp);
        temp = temp->next;
    }
    temp = dummyHead->next;
    temp->prev = nullptr;
    delete dummyHead;
    return temp;
}

void optimal(ListNode** head_ref, int x){
    ListNode* temp = *head_ref;
    while(temp){
        ListNode* front = temp->next;
        if(temp->val == x){
            if(temp == *head_ref) *head_ref = front;
            
            if(temp->prev) temp->prev->next = temp->next;
            if(temp->next) temp->next->prev = temp->prev;
            delete temp;
        }
        temp = front;
    }
}

int main(){
    // Given the head_ref of a doubly Linked List and a Key. Delete all occurrences of the given key if it is present in the original dll.
    ListNode* head = dllFromArray( {2,1,2,3,2,5} );
    // your code below

    // Optimal Solution: O(n), O(1)
    // If the node to delete is head, update it to the next one. For start and end nodes add a condition to check if next and prev exist, if they dont then nothing, if they do then update their pointers to skip over current node.
    optimal(&head, 2);

    // your code above
    ListNode* temp = head;
    while(temp){
        cout<<temp->val;
        if(temp->next) cout<<" -> ";
        temp = temp->next;
    }
    cout<<"\n\n";
    return 0;
}