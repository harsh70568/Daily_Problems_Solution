/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* item = head;
        while(curr)
        {
            item = curr->next;
            Node* copy = new Node(curr->val);
            curr->next = copy;
            copy->next = item;
            curr = item;
        }
        
        curr = head;
        while(curr)
        {
            item = curr->next->next;
            if(curr->random) curr->next->random = curr->random->next;
            curr = item;
        }
        
        Node* dummy = new Node(0);
        Node* temp = dummy;
        curr = head;
        while(curr)
        {
            item = curr->next->next;
            temp->next = curr->next;
            curr->next = item;
            temp = temp->next;
            curr = item;
        }
        return dummy->next;
    }
};