//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string p, string t) {
	    // code here
	    int k = p.length();
	    
	    vector<int> freq1(26, 0);
	    vector<int> freq2(26, 0);
	    
	    for(int i = 0; i < p.length(); i++) freq2[p[i] - 'a']++;
	    
	    int i = 0;
	    int j = 0;
	    int cnt = 0;
	    while(j < t.length())
	    {
	        if(p.find(t[j]) != string::npos)
	        {
	            freq1[t[j] - 'a']++;
	        }
	        
	        if(j-i+1 < k) j++;
	        else if(j-i+1 == k)
	        {
	            if(freq1 == freq2) cnt++;
	            if(p.find(t[i]) != string::npos) freq1[t[i] - 'a']--;
	            i++;
	            j++;
	        }
	    }
	    
	    
	    return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends