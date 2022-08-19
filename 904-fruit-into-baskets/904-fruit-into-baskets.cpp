class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k = 2;
        int i = 0;
        int j = 0;
        int maxi = -1;
        unordered_map<int,int> mpp;
        while(j < fruits.size())
        {
            mpp[fruits[j]]++;
            if(mpp.size() <= k)
            {
                maxi = max(maxi,j-i+1);
                j++;
            }
            else if(mpp.size() > k)
            {
                while(mpp.size() > k)
                {
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};