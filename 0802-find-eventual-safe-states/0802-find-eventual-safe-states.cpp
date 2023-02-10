class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> ans;
        
        vector<int> adj[n];
        vector<int> indegree(n);
        // reverse edges
        for(int i = 0; i < n; i++)
        {
            // edge stored = i -> it
            // now stored as = it -> i
            for(auto it : g[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};