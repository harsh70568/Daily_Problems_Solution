//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void solve(int index, string &s, string &temp, vector<string> &ans)
	{
	    if(index >= s.length())
	    {
	        if(temp != "") ans.push_back(temp);
	        return;
	    }
	    
	    // pick
	    temp += s[index];
	    solve(index+1, s, temp, ans);
	    temp.pop_back();
	    
	    // not-pick
	    solve(index+1, s, temp, ans);
	}
		vector<string> AllPossibleStrings(string s){
		    string temp = "";
		    vector<string> ans;
		    solve(0, s, temp, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends