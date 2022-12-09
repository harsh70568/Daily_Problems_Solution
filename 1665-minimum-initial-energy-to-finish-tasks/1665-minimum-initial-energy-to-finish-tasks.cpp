class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        return (a[1] - a[0]) > (b[1] - b[0]);
    }
    bool is_possible(vector<vector<int>> &tasks, int mid)
    {
        for(int i = 0; i < tasks.size(); i++)
        {
            if(tasks[i][1] > mid) return false;
            
            mid -= tasks[i][0];
        }
        
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), cmp);
        int sum = 0;
        for(auto it : tasks)
        {
            sum += it[1];
        }
        
        int low = 1;
        int high = sum;
        
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            
            if(is_possible(tasks, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};