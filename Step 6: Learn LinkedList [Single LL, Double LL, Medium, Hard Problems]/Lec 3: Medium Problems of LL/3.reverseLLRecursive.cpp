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
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* front = head->next;
    ListNode* newHead = optimal(front);
    front->next = head;
    head->next = nullptr;
    return newHead;
}

int main(){
    // Given the head of a singly linked list, reverse the list recursively, and return the reversed list.
    ListNode* head = llFromArray( {1,2,3,4,5,6} );
    // 1->2->3->4->5->6->x
    // your code below

    // Optimal Solution: O(n), O(1)
    // First thing to notice is we are returning the last node. Once it gets set into newHead we keep returning newHead only. Next we reverse the 2 element ll by simply keeping a front after head, and setting their pointers accordingly. We return front(for 2 ll newHead is just front) but when a 3 element ll would have called the function to reverse the latter two elements, its first element would still be pointing to original head of this now reversed 2 element ll, so we can keep recursively doing it.
    // 1 -> 2 -> 3 -> x
    // calling it with 1 as the head would set front1 to 2, head1 to 1 and call the function again with 2 as the head, keep in mind whatever is returned is newHead
    // calling it with 2 as the head would set front2 to 3, head2 to 2 and call the function again with 3 as the head, whatever is returned is newHead and will bubble upwards to the final return
    // calling it with 3 will directly return this 3 as now the ll has only single element
    // func2 will receive 3 as its newHead, and this is the correct head for the final reversed ll. func2 will ultimately set 3->2->x, for func2 front2 is 3, head2 is 2
    // func1 will again recieve 3 as newHead and it will ultimately return this to the line below for answer to store. Note 1 still points to front1 which is 2, so the ll has become (3,1)->2->x now we just need to set 1 to after 2, and head1 is 1, so front1's next becomes head1 and head1 points to null.
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