class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;
        int max_len = 1;
        map<int, int> mpp;
        while(j < fruits.size())
        {
            mpp[fruits[j]]++;
            if(mpp.size() <= 2)
            {
                max_len = max(max_len, j-i+1);
                j++;
            }
            else if(mpp.size() > 2)
            {
                while(mpp.size() > 2)
                {
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        
        return max_len;
    }
};