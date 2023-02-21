//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        int zero_cnt = 0;
        int one_cnt = 0;
        int two_cnt = 0;
        while(head)
        {
            if(head->data == 0) zero_cnt++;
            else if(head->data == 1) one_cnt++;
            else if(head->data == 2) two_cnt++;
            head = head->next;
        }
        
        //cout<<one_cnt<<endl;
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        while(zero_cnt--)
        {
            Node* temp = new Node(0);
            curr->next = temp;
            curr = temp;
        }
        
        while(one_cnt--)
        {
            Node* temp = new Node(1);
            curr->next = temp;
            curr = temp;
        }
        
        while(two_cnt--)
        {
            Node* temp = new Node(2);
            curr->next = temp;
            curr = temp;
        }
        
        curr->next = NULL;
        
        return dummy->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends