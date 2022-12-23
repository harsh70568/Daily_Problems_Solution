class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool> &vis, int &cnt)
    {
        vis[node] = 1;
        
        for(auto &it : adj[node])
        {
            if(vis[it] == 0)
            {
                cnt++;
                dfs(it, adj, vis, cnt);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> vis(n, 0);
        vector<int> conn;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                int no_of_nodes_it_connects = 1;
                dfs(i, adj, vis, no_of_nodes_it_connects);
                conn.push_back(no_of_nodes_it_connects);
            }
        }
        
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i < conn.size(); i++)
        {
            sum += conn[i];
            ans += (conn[i] * 1LL * (n - sum));
            
        }
        
        return ans;
    }
};