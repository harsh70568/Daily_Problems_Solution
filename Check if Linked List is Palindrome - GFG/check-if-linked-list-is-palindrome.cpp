//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* head)
    {
        Node* p = head;
        Node* q = NULL;
        Node* r = NULL;
        
        while(p)
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r;
        }
        
        return q;
    }
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* slow = head;
        Node* fast = head;
       // Node* temp = NULL;
        
        while(fast && fast->next)
        {
           // temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //temp->next = NULL;
        Node* head2 = reverse(slow);
        
        while(head2)
        {
            if(head->data != head2->data)
            {
                return false;
            }
            
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends