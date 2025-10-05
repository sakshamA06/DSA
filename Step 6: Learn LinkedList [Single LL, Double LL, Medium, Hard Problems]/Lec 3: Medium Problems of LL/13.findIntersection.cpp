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

ListNode* moveForward(ListNode* head, int n){
    while(n--){
        head = head->next;
    }
    return head;
}
ListNode* better(ListNode *headA, ListNode *headB) {
    int lengthA = 0;
    int lengthB = 0;
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    while(tempA){
        lengthA++;
        tempA = tempA->next;
    }
    while(tempB){
        lengthB++;
        tempB = tempB->next;
    }
    tempA = headA;
    tempB = headB;
    
    int d = lengthA - lengthB;
    if(d > 0) tempA = moveForward(tempA, d);
    else if(d < 0) tempB = moveForward(tempB, -d);

    while(tempA){
        if(tempA == tempB) return tempA;
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return nullptr;
}

ListNode* optimal(ListNode* headA, ListNode* headB){
    if(!headA || !headB) return nullptr;
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    while(tempA != tempB){
        tempA = tempA->next;
        tempB = tempB->next;
        if(tempA == tempB) return tempA;
        
        if(!tempA) tempA = headB;
        if(!tempB) tempB = headA;
    }
    return tempA;
}

int main(){
    // Given the heads of two singly linked-lists headA and headB of size m and n, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
    ListNode* head1 = llFromArray( {4,1,8,4,5} );
    ListNode* head2 = llFromArray( {5,6,1} );
    head2->next->next->next = head1->next->next; // last 1 of head2 is connected to 8 of head1
    // your code below

    // Brute Force: O(m + n), O(m)
    // TC: if unordered map takes O(1) then this TC otherwise multiply it by the sum of TC of storing and finding in the map.
    // SC: Assuming m is the smaller list.
    // Store all the nodes of one of the lists in a map, then go through the other and search each of its node in the map. First found node is the intersection, if not found return nullptr.

    // Better Solution: O(m + 2n), O(1)
    // TC: m+n for finding lengths of both lists, then the longer list's temp catches up to the other and they move along till the end. So the longer list is traversed once more. Say its n, we have m+n + n = m+2n
    // Find the length of both lists, get the difference, this difference is the amount longer list is longer than the other. So basically the length of its tail.
    // tempA
    //    ↓
    //    4->1
    //       ↓
    //       8->4->5->x
    //       ↑
    // 5->6->1
    //  ↖tempB
    // The difference d is the amount tempB has to move to match up with tempA, after that they both can move together to end up at the intersection.
    // ListNode* answer = better(head1, head2);

    // Optimal Solution: O(m+n), O(1)
    // Just move tempA and tempB both at the same time, when any of them reaches nullptr, move them back to the head of the other list. So tempA will reach the end and move to headB, same for tempB, it will move to headA. After this they will automatically be lined up and now moving together will result them being on the intersection at the same time.
    // This works because in the start tempA is 1 node ahead of tempB, after tempA moves to headB, it will have to traverse the same amount of nodes it was ahead until tempB moves to headA. You can also think of it as tempA covers m then n nodes, tempB covers n then m nodes, so they traverse the same amount m+n, now seeing it in reverse, they have travelled m+n so they would have reached end, rewinding time, they would have been on same common sublist(8->4->5) for their last three traverses. We just return the first common node as thats the intersection.
    // Now for some technical details, you need to check tempA == tempB before wrapping them around to heads, as when they both simultaneously reach the end, they both will wrap around and it will result in an infinite loop for non intersecting lists. As a consequence the condition in while loop is tempA != tempB, this is for the edge case that both lists are the same, head1 and head2 are same, you won't catch this normally if the check is after they move, but we have to keep the check between their movement and wrapping, as we wont be able to detect them both at the end together, they will wrap around and we will never detect when to end in case of no intersection.(this is if the check condition was above their movement)
    ListNode* answer = optimal(head1, head2);

    // your code above
    cout<<"Intersection node is: "<<(answer ? answer->val : 0);

    cout<<"\n\n";
    return 0;
}