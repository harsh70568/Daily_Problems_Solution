class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> topo;
        vector<int> indegree(n);
        vector<int> adj[n];
        
        for(int i = 0; i < pre.size(); i++)
        {
            indegree[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() != n) return {};
        return topo;
    }
};