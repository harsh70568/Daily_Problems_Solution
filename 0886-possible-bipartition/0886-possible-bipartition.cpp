class Solution {
public:
    // color it with either 0 or 1.
    bool bfs(int start, vector<int> &col, vector<int> adj[])
    {
        queue<int> q;
        q.push(start);
        col[start] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : adj[node])
            {
                if(col[it] == -1)
                {
                    col[it] = !col[node];
                    q.push(it);
                }
                else if(col[it] == col[node]) return false;
            }
        }
        
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n+1];
        for(int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
            
        }
        vector<int> col(n+1,-1);
        for(int i = 1; i <= n; i++)
        {
            if(col[i] == -1)
            {
                if(bfs(i, col, adj) == false) return false;
            }
        }
        
        return true;
    }
};