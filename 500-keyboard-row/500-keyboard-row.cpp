class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> mpp;
        vector<string> ans;
        for(auto it : "qwertyuiopQWERTYUIOP") mpp[it] = 1;
        for(auto it : "asdfghjklASDFGHJKL") mpp[it] = 2;
        for(auto it : "zxcvbnmZXCVBNM") mpp[it] = 3;
        
        for(auto it : words)
        {
            string str = it;
            int i;
            int index = mpp[str[0]];
            for(i = 1; i < str.length(); i++)
            {
                if(mpp[str[i]] != index)
                {
                    break;
                }
            }
            if(i == str.length())
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};