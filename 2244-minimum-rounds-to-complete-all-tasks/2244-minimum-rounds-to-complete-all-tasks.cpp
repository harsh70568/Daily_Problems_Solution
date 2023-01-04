class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mpp;
        for(int i = 0; i < tasks.size(); i++)
        {
            mpp[tasks[i]]++;
        }
        
        int cnt = 0;
        for(auto it : mpp)
        {
            if(it.second == 1) return -1;
            while(it.second > 5)
            {
                it.second -= 3;
                cnt++;
            }
            if(it.second <= 3) cnt++;
            else if(it.second <= 5) cnt += 2;
        }
        
        return cnt;
        
        
    }
};