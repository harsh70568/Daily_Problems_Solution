class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
          int n = rooms.size();
        bool vis[n];
        for(int i=0;i<n;i++)
           vis[i]=false;
        vis[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int h = q.front();
            q.pop();
            for(auto x: rooms[h]) 
            if(vis[x]==false) {
                q.push(x);
                vis[x]=true;
            }
        }
        for(int i=0;i<n;i++) {
            if(vis[i]==false)
                return false;
        }
        return true;
    }
};