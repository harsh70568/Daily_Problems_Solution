class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char,int> mpp;
        int count = 0;
        for(int i = 0; i < num.length(); i++)
        {
            mpp[num[i]]++;   
        }
        
        int i = 0;
        while(i < num.length())
        {
            if(mpp[i + '0'] != (num[i] - '0'))
            {
                return false;
            }
            i++;
        }
        
        return true;
    }
};