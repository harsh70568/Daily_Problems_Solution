class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> mpp;
        int count = 0;
        for(int i = 0; i < jewels.length(); i++)
        {
            mpp[jewels[i]]++;
        }
        
        for(auto it : stones)
        {
            if(mpp.find(it) != mpp.end()) count++;
        }
        
        return count;
    }
};