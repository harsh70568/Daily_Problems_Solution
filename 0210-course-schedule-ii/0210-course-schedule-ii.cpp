class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> adj[num];
        
        for(int i = 0; i < pre.size(); i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        
        vector<int> indeg(num,0);
        for(int i = 0; i < num; i++)
        {
            for(auto it : adj[i])
            {
                indeg[it]++;
            }
        }
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < num; i++)
        {
            if(indeg[i] == 0) q.push(i);
        }
        
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto it : adj[node])
            {
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        
        if(topo.size() != num) return {};
        else return topo;
    }
};