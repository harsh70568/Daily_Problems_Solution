//{ Driver Code Starts
#include<iostream>

#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}


// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int length(Node* head)
{
    int c = 0;
    while(head)
    {
        c++;
        head = head->next;
    }
    
    return c;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1 = length(head1);
    int len2 = length(head2);
    
    Node* first = NULL;
    Node* second = NULL;
    int diff = abs(len1-  len2);
    
    if(len1 >= len2)
    {
        first = head1;
        second = head2;
    }
    else
    {
        first = head2;
        second = head1;
    }
    
    while(diff--)
    {
        first = first->next;
    }
    
    while(first && second)
    {
        if(first == second)
        {
            return first->data;
        }
        first = first->next;
        second = second->next;
    }
    
    return -1;
}

