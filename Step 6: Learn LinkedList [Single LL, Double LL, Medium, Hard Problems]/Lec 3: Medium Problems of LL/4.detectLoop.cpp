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

bool optimal(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

int main(){
    // Given the head of a ll, return whether it has a loop in it.
    ListNode* head = llFromArray( {1,2,3,4,5} );
    head->next->next->next->next->next = head->next->next; // 5 loops back to 3
    // 1->2->3->4->5->3->4->5->3->......
    // your code below

    // Brute Force: O(n * 2 * log n), O(n)
    // Traverse the list, store each node in a map, and in each iteration check if the current node is already in the map, if yes then we have came back to a node via a loop so return true, otherwise add the node to the map and move forward.
    // If by the end there were no matches found then return false.

    // Optimal Solution: O(n), O(1)
    // If there isnt a loop, the while condition will eventually become false and function will return false.
    // If there is a loop, then both pointers must get stuck in it, there is no way to skip or get out.
    // Once both pointers are inside the loop, call the distance fast has to travel forwards to get to slow revolving around the ring be d.
    // So slow rotate by 1, fast by 2, in the same direction, and hence after each iteration fast will be 2-1 = 1 node closer to slow, now whatever d is, it becomes d-1 in the next iteration and hence will always reach 0 meaning they both collided.
    // In the example above, the loop starts at 3, when slow gets to 3, fast is at 5, which is one behind 3, so in the next iteration slow moves to 3->4, and fast to 5->3->4 and they collide.
    bool answer = optimal(head);

    // your code above
    cout<<(answer ? "Loop detected." : "No loop detected.");

    cout<<"\n\n";
    return 0;
}