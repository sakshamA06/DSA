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

int bf(ListNode* head){
    unordered_map<ListNode*, int> mpp;
    int index = 1;
    while(head){
        if(mpp.find(head) != mpp.end()){
            return index-mpp[head];
        }
        mpp.emplace(head, index);
        head = head->next;
        index++;
    }
    return 0;
}

int optimal(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            // Now both slow and fast are at the same place, just looping around now.
            fast = fast->next;
            int length = 1;
            while(fast != slow){
                fast = fast->next;
                length++;
            }
            return length;
        };
    }
    return 0;
}

int main(){
    // Given the head of a linked list, return the length of its loop. Return 0 if no loops present.
    ListNode* head = llFromArray( {1,2,3,4,5} );
    head->next->next->next->next->next = head->next; // 5 loops back to 2
    // 1->2->3->4->5->2->3->4->5->2->......
    // your code below

    // Brute Force: O(n * 2 * log n), O(n)
    // Traverse the list, store each node as a key in a map with its index as the value, and in each iteration check if the current node is already in the map, if yes then the difference between current node's index and index of that node previously stored is the length of the loop, return it, otherwise add the node to the map and move forward.
    // 1-based index tells at which position the node is, say the starting node of loop's index is 5, now after rotating around the loop the index of that starting node will be the loop's length added to 5. So direct difference gives the length, not being off by 1.
    // If by the end there were no matches found then return 0.
    // int answer = bf(head);

    // Optimal Solution: O(n), O(1)
    // When you reach the same node via turtoise and hare algo, just loop around once with one of the pointers until u reach the other one(signaling the end of the loop) and keep a count of nodes.
    int answer = optimal(head);

    // your code above
    cout<<"Length of loop: "<<answer;

    cout<<"\n\n";
    return 0;
}