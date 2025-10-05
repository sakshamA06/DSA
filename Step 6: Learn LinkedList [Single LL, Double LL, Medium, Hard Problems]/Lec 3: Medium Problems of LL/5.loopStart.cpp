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
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main(){
    // Given the head of a linked list, return the node where the loop begins. If there is no loop, return null.
    ListNode* head = llFromArray( {1,2,3,4,5} );
    head->next->next->next->next->next = head->next->next; // 5 loops back to 3
    // 1->2->3->4->5->3->4->5->3->......
    // your code below

    // Brute Force: O(n * 2 * log n), O(n)
    // Traverse the list, store each node as a key in a map with its index as the value, and in each iteration check if the current node is already in the map, if yes then the stored index is the starting point of the loop, return the node, otherwise add the node to the map and move forward.
    // If by the end there were no matches found then return nullptr.

    // Optimal Solution: O(n), O(1)
    // Normal loop detection logic using turtoise and hare algorithm. If no loops detected, return nullptr otherwise after they collide, set slow to head and keep moving both slow and fast by one. They are guaranteed to collide again at the starting node of the loop. When they do, return either slow or fast.
    // Now the why:
    // Say the length of loop is L. Also since fast travels at twice the speed of slow, it will cover twice the distance. say slow covered l, then fast would cover 2l, which also means the distance from slow to fast is l.
    // <-----l----->slow<-----l----->fast
    // <-------------2l------------->fast
    // So say slow covered l, when its on first node of the loop. Say fast needs to cover d distance to get to slow. Or in other words distance from fast to slow is d, and slow to fast is l. And so total length of loop L = d+l Now from here we rotate around the loop until they collide. Since each iteration slow moves one node head, and d reduces by 1, when d gets to 0 in d steps, slow will have moved d nodes. Since total length of loop was l+d, and slow covered d from starting point, after anohter l steps it would reach the starting point again. Note that fast is also at the same node rn cuz they collided. Now just set slow to head, and head to starting point is l by definition, when moving both slow and fast by one at once, fast will cover l in loop and reach starting point, slow will cover l out of loop and reach starting point and they will collide. Now both slow and fast are at starting point, return any one.
    // It doesnt matter if fast loops around many times before slow reaches the starting point, just count entire loops around in the distance too. Like instead of reducing 361° to 1°, just keep it to 361°. Meaning dont see l as direct distance from slow to fast, count the loops fast did in that distance too. By doing this, all the calculation we did with l and d remain the same.
    ListNode* answer = optimal(head);

    // your code above
    cout<<answer->val;

    cout<<"\n\n";
    return 0;
}