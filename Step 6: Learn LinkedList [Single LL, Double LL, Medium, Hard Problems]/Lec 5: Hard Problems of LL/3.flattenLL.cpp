#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() : val(0), next(nullptr), child(nullptr) {}
    ListNode(int x) : val(x), next(nullptr), child(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *child) : val(x), next(next), child(child) {}
};
ListNode* llFromArray(vector<vector<int>> arr){
    if(arr.size() == 0) return nullptr;
    ListNode dummy(-1);
    ListNode* temp = &dummy;
    
    for(int i = 0; i < arr.size(); i++){
        temp->next = new ListNode(arr[i][0]);
        temp = temp->next;
        ListNode* t1 = temp;
        for(int j = 1; j < arr[i].size(); j++){
            t1->child = new ListNode(arr[i][j]);
            t1 = t1->child;
        }
    }

    return dummy.next;
}
string pad(int x){
    return ((x/10) ? to_string(x) : "0"+to_string(x));
}

ListNode* merge(ListNode* head1, ListNode* head2){
    ListNode dummy(0);
    ListNode* temp = &dummy;

    while(head1 && head2){
        if(head1->val <= head2->val){
            temp->child = head1;
            head1 = head1->child;
        }
        else{
            temp->child = head2;
            head2 = head2->child;
        }
        temp = temp->child;
        temp->next = nullptr;
    }
    temp->child = (head1 ? head1 : head2);
    if(temp->child) temp->child->next = nullptr;

    return dummy.child;
}
ListNode* optimal(ListNode* head){
    if(!head || !head->next) return head;
    ListNode* mergedHead = optimal(head->next);

    return merge(head, mergedHead);
}

int main(){
    // Given the head of a linked list in which each node has an additional child pointer which points to other nodes which have nullptr in their next. Vertically each sublist made with child node is sorted. Flatten the list vertically and return the head such that traversing child nodes gives the entire sorted list.
    ListNode* head = llFromArray({ {3}, {2,10}, {1,7,11,12}, {4,9}, {5,6,8} });
    // 3 -> 2 -> 1 -> 4 -> 5
    //      ↓    ↓    ↓    ↓     
    //      10   7    9    6    
    //           ↓         ↓     
    //           11        8    
    //           ↓                 
    //           12
    // your code below

    // Optimal Solution: O(n*n*m), O(n)
    // TC: n is the amount of head nodes, m is the length of sublist made with child nodes, basically the depth for each head node. First time we merge last two both are m deep, so it takes O(2m), then we merge that 2m list with last third which is m deep so that merge will take O(3m) and so on for all n. So 2m+3m+4m+...+nm = (2+3+4+...n) * m = (n(n+1)/2 -1) * m => ultimately O(n*n*m)
    // SC: Recursive stack space, it goes n level deep so O(n)
    // Merge last two lists(the list connected by child nodes), then merge that with last third and so on going right to left until u finally merge the accumulated list with the first list.
    ListNode* answer = optimal(head);

    // your code above
    ListNode* temp = answer;
    bool prettyPrint = false;
    if(!prettyPrint){
    while(temp){
        ListNode* t1 = temp;
        cout<<"(";
        while(t1){
            cout<<t1->val;
            if(t1->child) cout<<"↘";
            t1 = t1->child;
        }
        cout<<")";
        if(temp->next) cout<<" -> ";
        temp = temp->next;
    }
    }

    else{ // uselessly messy code to print the structure properly
    bool printed = true;
    int level = 0;
    while(printed){
        printed = false;
        temp = head;
        while(temp){
            ListNode* t1 = temp;
            for(int i = 0; i < level; i++) if(t1) t1 = t1->child;
            if(t1){
                cout<<pad(t1->val);
                if(!level && temp->next) cout<<" -> ";
                if(level) cout<<"    ";
                printed = true;
            }
            else cout<<"      ";
            temp = temp->next;
        }
        cout<<endl;
        level++;
        temp = head;
        while(temp){
            ListNode* t1 = temp;
            for(int i = 0; i < level; i++) if(t1) t1 = t1->child;
            cout<<(t1 ? "↓     " : "      ");
            temp = temp->next;
        }
        cout<<endl;
    }
    }

    cout<<"\n\n";
    return 0;
}