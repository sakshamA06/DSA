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

ListNode* mySol(ListNode* head){
    ListNode* firstZero = nullptr;
    ListNode* firstOne = nullptr;
    ListNode* firstTwo = nullptr;
    ListNode* lastZero = nullptr;
    ListNode* lastOne = nullptr;
    ListNode* lastTwo = nullptr;
    ListNode* temp = head;
    while(temp){
        if(temp->val == 0){
            if(firstZero){
                lastZero->next = temp;
            }
            else firstZero = temp;
            lastZero = temp;
        }
        else if(temp->val == 1){
            if(firstOne){
                lastOne->next = temp;
            }
            else firstOne = temp;
            lastOne = temp;
        }
        else if(temp->val == 2){
            if(firstTwo){
                lastTwo->next = temp;
            }
            else firstTwo = temp;
            lastTwo = temp;
        }
        temp = temp->next;
    }
    head = (firstZero ? firstZero : (firstOne ? firstOne : firstTwo));
    if(lastZero) lastZero->next = (firstOne ? firstOne : firstTwo);
    if(lastOne) lastOne->next = firstTwo;
    if(lastTwo) lastTwo->next = nullptr;

    // For arranging in 1s -> 0s -> 2s order
    // head = (firstOne ? firstOne : (firstZero ? firstZero : firstTwo));
    // if(lastOne) lastOne->next = (firstZero ? firstZero : firstTwo);
    // if(lastZero) lastZero->next = firstTwo;
    // if(lastTwo) lastTwo->next = nullptr;
    
    return head;
}

int main(){
    // Given the head of a linked list containing only 0s, 1s and 2s, return the head of the sorted list.
    ListNode* head = llFromArray( {2,2,0,1,0,1,2,0} );
    // your code below

    // My Solution: O(n), O(1)
    // Keep track of first and last 0s, 1s and 2s. At the end link them properly. You can simply do it by assigning 0 if it exists, if it doesnt then 1 if it exists, if not then 2. All four last lines follow this.
    // You can even change the order of 0,1,2 by simply changing the order in which you link these first012s to last012s
    ListNode* answer = mySol(head);

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