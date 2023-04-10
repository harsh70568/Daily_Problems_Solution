//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int n = str.length();
        int zero_cnt = 0;
        int one_cnt = 0;
        
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(str[i] == '0')
            {
                zero_cnt++;
                if(zero_cnt == one_cnt)
                {
                    zero_cnt = 0;
                    one_cnt = 0;
                    cnt++;
                }
            }
            else
            {
                one_cnt++;
                if(zero_cnt == one_cnt)
                {
                    zero_cnt = 0;
                    one_cnt = 0;
                    cnt++;
                }
            }
        }
        
        if(zero_cnt == 0 && one_cnt == 0) return cnt;
        else return -1;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends