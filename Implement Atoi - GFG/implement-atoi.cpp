// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int num = 0;
        int sign = 1;
        int i = 0;
        if(str[i] == 45)
        {
            sign = -1;
            i++;
        }
        
        for(; i < str.length(); i++)
        {
            if(str[i] >=  48 && str[i] <= 57)
            {
                num = num*10+(str[i] - '0');
            }
            else
            {
                return -1;
            }
        }
        return num*sign;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends