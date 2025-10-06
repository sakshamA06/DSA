#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *random;
    ListNode() : val(0), next(nullptr), random(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *random) : val(x), next(next), random(random) {}
};

ListNode* llFromArray(vector<pair<int, int>> arr){
    if(arr.size() == 0) return nullptr;
    ListNode dummy(0);
    ListNode* temp = &dummy;
    for(int i = 0; i < arr.size(); i++){
        temp->next = new ListNode(arr[i].first);
        temp = temp->next;
    }
    temp = dummy.next;
    for(int i = 0; i < arr.size(); i++){
        ListNode* t1 = dummy.next;
        if (arr[i].second == -1) t1 = nullptr;
        else
        for(int j = 0; j < arr[i].second; j++){
            t1 = t1->next;
        }
        temp->random = t1;
        temp = temp->next;
    }
    return dummy.next;
}

ListNode* bf(ListNode* head){
    if(!head) return head;
    unordered_map<ListNode*, ListNode*> mpp;
    
    ListNode* temp = head;
    while(temp){
        mpp.emplace(temp, new ListNode(temp->val));
        temp = temp->next;
    }
    temp = head;
    while(temp){
        mpp[temp]->next = mpp[temp->next];
        mpp[temp]->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[head];
}

ListNode* optimal(ListNode* head){
    // create copy nodes after original ones
    ListNode* temp = head;
    while(temp){
        ListNode* front = temp->next;
        temp->next = new ListNode(temp->val);
        temp->next->next = front;
        temp = front;
    }
    // link random pointers correctly
    temp = head;
    while(temp){
        temp->next->random = (temp->random ? temp->random->next : nullptr);
        temp = temp->next->next;
    }
    // repair og list, separate the copy by fixing both of their next pointers
    temp = head;
    ListNode* newHead = temp->next;
    ListNode* temp2 = newHead;
    while(temp){
        temp->next = temp->next->next;
        temp2->next = (temp2->next ? temp2->next->next : nullptr);
        temp = temp->next;
        temp2 = temp2->next;
    }
    return newHead;
}

int main(){
    // Question
    ListNode* head = llFromArray( {{7,-1},{13,0},{11,4},{10,2},{1,0}} );
    // your code below

    // Brute Force: O(2n), O(n)
    // Simply create dangling nodes and store them in a hashmap, once the entire ll is copied, just traverse the og ll again to make the links between the dangling nodes.
    // ListNode* answer = bf(head);

    // Optimal Solution: O(3n), O(1)
    // Insert the copy nodes just after their original counterparts, then link the random pointers, this is easy since the random of og node is just before the intended random node for the copied node(after og node). Finally fix the next pointers by making them jump their immediate next node as thats the node of the other list.
    ListNode* answer = optimal(head);

    // your code above
    ListNode* temp = answer;
    while(temp){
        cout<<"(";
        cout<<temp->val;
        cout<<" => ";
        cout<<(temp->random ? temp->random->val : -1);
        cout<<")";
        if(temp->next) cout<<" -> ";
        temp = temp->next;
    }

    cout<<"\n\n";
    return 0;
}