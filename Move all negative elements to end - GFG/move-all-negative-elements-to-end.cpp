//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.first > 0 && b.first > 0)
        {
            return a.second < b.second;
        }
        else if(a.first < 0 && b.first < 0)
        {
            return a.second < b.second;
        }
        else
        {
            return a.first > b.first;
        }
    }
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        vector<pair<int, int>> temp;
        for(int i = 0; i < n; i++)
        {
            temp.push_back({arr[i], i});
        }
        
        sort(temp.begin(), temp.end(), cmp);
        
        for(int i = 0; i < n; i++)
        {
            arr[i] = temp[i].first;
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends