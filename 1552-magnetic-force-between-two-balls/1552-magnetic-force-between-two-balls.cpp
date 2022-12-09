class Solution {
public:
    bool is_possible_to_place(vector<int> &pos, int mid, int m)
    {
        int count = 1;
        int prev = pos[0];
        
        for(int i = 1; i < pos.size(); i++)
        {
            if(pos[i] - prev >= mid)
            {
                count++;
                prev = pos[i];
            }
        }
        
        return count >= m;
    }
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int low = 1;
        int high = pos[pos.size()-1] - pos[0];
        int ans = 0;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            
            if(is_possible_to_place(pos, mid, m))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};