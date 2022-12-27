class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        vector<int> temp;
        for(int i = 0; i < rocks.size(); i++)
        {
            temp.push_back(abs(capacity[i] - rocks[i]));
        }
        
        sort(temp.begin(), temp.end());
        
        //for(int i = 0; i < temp.size(); i++) cout<<temp[i]<<" ";
        
        int ans = 0;
        for(int i = 0; i < temp.size(); i++)
        {
            if(add < temp[i]) return ans;
            ans++;
            add -= temp[i];
            
        }
        return ans;
        
        
    }
};