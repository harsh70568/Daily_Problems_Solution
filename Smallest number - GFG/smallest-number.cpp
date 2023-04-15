//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int sum, int D){
       string ans = "";
       
       while(D)
       {
           if(sum <= 9)
           {
               if(D > 1)
               {
                   ans += to_string(sum-1);
                   D = D - 2;
                   while(D)
                   {
                       ans += to_string(0);
                       D--;
                   }
                   ans += to_string(1);
                   sum = 0;
                   D = 0;
                   break;
               }
               else
               {
                   if(sum > 9) return "-1";
                   ans += to_string(sum);
                   sum = 0;
                   D = 0;
                   break;
               }
           }
           else
           {
               ans += '9';
               sum -= 9;
               D--;
           }
           
       }
       
       if(sum > 0) return "-1";
       reverse(ans.begin(), ans.end());
       return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends