class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;
        sort(potions.begin(),potions.end());
        int i = 0;
        while(i < n)
        {
            int low = 0;
            int high = m-1;
            while(low <= high)
            {
                int mid = (low+high)/2;
                if((long long)spells[i]*potions[mid] >= success)
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            ans.push_back(m-low);
            i++;
        }
        return ans;
    }
};