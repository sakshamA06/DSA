Its a good practice to unlink a node from the rest of the data structure before deleting it.

The main point is to keep the data structure stable before deleting, it doesnt matter if the node to be deleted still points to somewhere in the list, what matters is nothing of your list points to that node.
```cpp
Node* deleteHead(Node* head){
if(head == nullptr) return head;
if(head->next == nullptr){
	delete head;
	return nullptr;
}

Node* oldHead = head;
head = head->next;
head->prev = nullptr; // now the list is stable
delete oldHead; // better than directly delete head->prev as that would be deleting a node when head->prev points to it, which can be done but isnt considered a good practice

return head;
}
// inside int main
head = deleteHead(head);

```


Whenever you need to create a new ll, you can create a dummy node whose next represents the head of your ll. This makes the implementation much cleaner.