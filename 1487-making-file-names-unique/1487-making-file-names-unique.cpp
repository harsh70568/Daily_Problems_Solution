class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        unordered_map<string, int> mpp;
        
        for(int i = 0; i < names.size(); i++)
        {
            if(mpp.find(names[i]) == mpp.end())
            {
                ans.push_back(names[i]);
                mpp[names[i]]++;
            }
            else
            {
                string temp = names[i];
                int val = mpp[temp];
                while(mpp.find(temp) != mpp.end())
                {
                    temp = names[i] + '(' + to_string(val) + ')';
                    val++;
                }
                ans.push_back(temp);
                mpp[temp]++;
                mpp[names[i]]++;
            }
        }
        
        return ans;
    }
};