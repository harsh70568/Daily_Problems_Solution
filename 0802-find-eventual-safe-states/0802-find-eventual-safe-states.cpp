class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &g)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : g[node])
        {
            if(vis[it] == 0)
            {
                if(dfs(it, vis, pathVis, g) == true) return true;
            }
            else if(pathVis[it] == 1) return true;
        }
        pathVis[node] = 0;
        
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> ans;
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, vis, pathVis, g);
            }
        }
        
        
        for(int i = 0; i < n; i++)
        {
            if(pathVis[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};