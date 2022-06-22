// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
int sum(int a,int b,string N)
{
    int res = 0;
    for(int i = a; i <= b; i++)
    {
        res += N[i]-'0';
    }
    return res;
}
	bool balancedNumber(string N)
	{
	    // code here
	    int size = N.length();
	    int mid = size/2;
	    int sum1 = sum(0,mid-1,N);
	    int sum2 = sum(mid+1,size-1,N);
	    if(sum1 == sum2) return 1;
	    else return 0;
	}
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string N;
        cin>>N;
        Solution ob;
        cout<<ob.balancedNumber(N)<<endl;
    }
    return 0;
}
  // } Driver Code Ends