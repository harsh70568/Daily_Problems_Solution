//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int> adj[N];
	    for(int i = 0; i < pre.size(); i++)
	    {
	        adj[pre[i].second].push_back(pre[i].first);
	    }
	    vector<int> indeg(N,0);
	    for(int i = 0; i < N; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indeg[it]++;
	        }
	    }
	    
	    queue<int> q;
	    vector<int> topo;
	    for(int i = 0; i < N; i++)
	    {
	        if(indeg[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        
	        topo.push_back(node);
	        
	        for(auto it : adj[node])
	        {
	            indeg[it]--;
	            if(indeg[it] == 0) q.push(it);
	        }
	    }
	    
	    return topo.size() == N;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends