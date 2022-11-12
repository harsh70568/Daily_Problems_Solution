//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    int i = 0;
		    int j = 0;
		    int maxi = -1;
		    int max_len = 1;
		    unordered_map<char, int> mpp;
		    while(j < s.length())
		    {
		        mpp[s[j]]++;
		        
		        maxi = max(maxi, mpp[s[j]]);
		        
		        if(j-i+1 - maxi > k)
		        {
		            mpp[s[i]]--;
		            i++;
		        }
		        
		        max_len = max(max_len, j-i+1);
		        j++;
		    }
		    
		    return max_len;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends