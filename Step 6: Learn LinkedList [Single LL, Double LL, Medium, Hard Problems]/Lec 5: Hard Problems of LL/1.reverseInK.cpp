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

ListNode* mySol(ListNode* head, int k){
    ListNode* rearguard = nullptr;
    ListNode* vanguard = nullptr;
    ListNode* p = nullptr;
    ListNode* c = head;
    ListNode* h = c;
    ListNode* temp = head;
    int count = 0;
    bool start = false;
    bool firstTime = true;
    while(temp){
        count++;
        vanguard = temp->next;
        if(count == k){
            temp->next = nullptr;
            start = true;
            count = 0;
        }
        if(start){
            if(rearguard) h = rearguard->next;
            c = h;
            p = nullptr;
            while(c){
                ListNode* n = c->next;
                c->next = p;
                p = c;
                c = n;
            }
            if(firstTime){
                head = p;
                firstTime = false;
            }
            if(rearguard) rearguard->next = p;
            h->next = vanguard;
            rearguard = h;
            start = false;
        }
        temp = vanguard;
    }
    return head;
}

ListNode* optimal(ListNode* head, int k){
    ListNode temp(0, head);

    ListNode* c = temp.next;
    ListNode* n = &temp;
    ListNode* p = &temp;
    int count = 0;
    while(c){
        count++;
        c = c->next;
    }
    while(count >= k){
        c = p->next;
        n = c->next;
        for(int i = 0; i < k-1; i++){ // moves k-1 nodes behind the current node one by one, effectively reversing the sublist
            c->next = n->next;
            n->next = p->next;
            p->next = n;
            n = c->next;
        }
        p = c;
        count -= k;
    }
    return temp.next;
}

int main(){
    // Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
    ListNode* head = llFromArray( {1,2,3,4,5} );
    int k = 2;
    // your code below

    // My Solution: O(2n), O(1)
    // Rearguard and vanguard are basically both ends of the section that we are reversing. 
    // ListNode* answer = mySol(head, k);
    
    // Optimal Solution: O(2n), O(1)
    // Much cleaner code. p always points to the node that points to the start of sublist that has to be reversed. c points to the node that will eventually become the tail, n points to the node that is currently being sent to the front of c, since c is the tail, p = c correctly moves p to before the next node of the next potential sublist to reverse.
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