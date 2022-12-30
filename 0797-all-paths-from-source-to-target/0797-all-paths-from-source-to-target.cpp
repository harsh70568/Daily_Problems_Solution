class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &temp, int node, int n)
    {
        if(node == n-1)
        {
            //temp.push_back(n-1);
            ans.push_back(temp);
        }
        
        for(auto it : graph[node])
        {
            temp.push_back(it);
            dfs(graph, ans, temp, it, n);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp = {0};
        int n = graph.size();
        
        dfs(graph, ans, temp, 0, n);
        
        return ans;
    }
};