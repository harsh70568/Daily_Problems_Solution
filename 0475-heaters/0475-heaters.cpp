class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size();
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        vector<int> left(n, INT_MAX);
        vector<int> right(n, INT_MAX);
        vector<int> mini(n, INT_MAX);
        
        // right array
        for(int i = 0, j = 0; i < houses.size() && j < heaters.size();)
        {
            if(houses[i] <= heaters[j])
            {
                left[i] = heaters[j] - houses[i];
                i++;
            }
            else
            {
                j++;
            }
        }
        
        // left array
        for(int i = n-1, j = heaters.size()-1; i >= 0 && j >= 0;)
        {
            if(houses[i] >= heaters[j])
            {
                right[i] = houses[i] - heaters[j];
                i--;
            }
            else
            {
                j--;
            }
        }
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            mini[i] = min(left[i], right[i]);
            maxi = max(maxi, mini[i]);

        }
        
        
        return maxi;
        
    }
};