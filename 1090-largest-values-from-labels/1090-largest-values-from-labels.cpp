class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        unordered_map<int,priority_queue<int>> mpp;
        
        for(int i = 0; i < n; i++)
        {
            mpp[labels[i]].push(values[i]);
        }
        vector<int> ans;
        for(auto it : mpp)
        {
            int temp = useLimit;
            while(!it.second.empty() && temp)
            {
                ans.push_back(it.second.top());
                it.second.pop();
                temp--;
            }
        }
        
        sort(ans.begin(),ans.end(),greater<int>());
        int sum = 0;
        int h = ans.size();
        int size = min(h,numWanted);
        for(int i = 0; i < size; i++)
        {
            sum += ans[i];
        }
        
        return sum;
    }
};