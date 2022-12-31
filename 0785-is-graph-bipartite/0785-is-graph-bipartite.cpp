class Solution {
public:
    bool bfs(int start, vector<int> &col, vector<vector<int>> &graph)
    {
        queue<int> q;
        q.push(start);
        col[start] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it : graph[node])
            {
                if(col[it] == -1)
                {
                    col[it] = !col[node];
                    q.push(it);
                }
                // if it is already colored with the same color as of its adjacent.
                else if(col[it] == col[node]) return false;
            }
        }
        
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        for(int i = 0; i < n; i++)
        {
            if(col[i] == -1)
            {
                if(bfs(i, col, graph) == false) return false;
            }
        }
        
        return true;
    }
};