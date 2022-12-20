class Solution {
public:
    void bfs(int node, vector<bool> &vis, vector<int> adj[])
    {
        queue<int> q;
        q.push(node);
        
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            
            for(auto it : adj[val])
            {
                if(vis[it] == 0)
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        vector<int> adj[n];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(n, false);
        
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                count++;
                vis[i] = 1;
                bfs(i, vis, adj);
            }
        }
        
        return count;
    }
};