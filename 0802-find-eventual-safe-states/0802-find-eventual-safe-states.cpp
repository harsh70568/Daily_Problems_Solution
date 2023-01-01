class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &graph)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : graph[node])
        {
            if(vis[it] == 0)
            {
                if(dfs(it, vis, pathVis, graph) == true) return true;
            }
            else if(pathVis[it] == 1) return true;
        }
        
        pathVis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, vis, pathVis, graph);
            }
        }
        
        // the nodes which dp not forms cycle or do not leads to the cycle will end up to the safe state.
        for(int i = 0; i < pathVis.size(); i++)
        {
            if(pathVis[i] == 0) ans.push_back(i);
        }
        
        return ans;
    }
};