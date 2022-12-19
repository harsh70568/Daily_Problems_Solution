class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        q.push(source);
        
        vector<int> vis(n,0);
        vis[source] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            if(node == destination) return true;
            
            for(auto it : adj[node])
            {
                if(vis[it] == 0)
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        
        return false;
        
        
    }
};