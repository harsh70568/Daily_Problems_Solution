// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here 
        int n = S.length();
        int start = 0;
        int max_length = 1;
        for(int i = 1; i < n; i++)
        {
            int left = i-1;
            int right = i;
            
            while(left >= 0 && right < n && S[left] == S[right])
            {
                if(max_length < right-left+1)
                {
                    max_length = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
            
            left = i-1;
            right = i+1;
            while(left >= 0 && right < n && S[left] == S[right])
            {
                if(max_length < right-left+1)
                {
                    max_length = right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return S.substr(start,max_length);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends