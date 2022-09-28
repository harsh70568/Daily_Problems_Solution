class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        
        unordered_map<string,int> mpp;
        
        for(int i = 0; i < cpdomains.size(); i++)
        {
            string temp = "";
            int num = 0;
            for(int j = 0; j < cpdomains[i].length(); j++)
            {
                if(cpdomains[i][j] == ' ')
                {
                    num = stoi(temp);
                    temp = "";
                }
                else temp += cpdomains[i][j];
            }
            mpp[temp] += num;
            string res = "";
            for(int i = temp.length()-1; i >= 0; i--)
            {
                if(temp[i] == '.')
                {
                    reverse(res.begin(),res.end());
                    mpp[res] += num;
                    reverse(res.begin(),res.end());
                    res += '.';
                }
                else
                {
                    res += temp[i];
                }
            }
        }
        
        for(auto it : mpp){
            string t = it.first;
            string str = to_string(it.second)+' '+t;
            ans.push_back(str);
        }
        
        return ans;
        
        
    }
};