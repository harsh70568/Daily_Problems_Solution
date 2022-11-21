//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/
#include<bits/stdc++.h>
class Solution {
public:
bool is_palindrome(string a)
{
    string b = a;
    reverse(b.begin(), b.end());
    
    return a == b;
    
}
    int PalinArray(int a[], int n)
    {
    	// code here
    	
    	for(int i = 0; i < n; i++)
    	{
    	    if(!is_palindrome(to_string(a[i]))) return 0;
    	}
    	
    	return 1;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends