class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        map<string,int> mpp;
        
        for(int i = 0; i < words.size(); i++)
        {
            string p,q;
            for(int j = 0; j < words[i].length(); j++)
            {
                if(j % 2 == 0) p += words[i][j];
                else q += words[i][j];
            }
            sort(p.begin(),p.end());
            sort(q.begin(),q.end());
            string temp = "";
            for(int k = 0; k < words[i].length()/2 + 1; k++)
            {
                temp += p[k];
                temp += q[k];
            }
            
            mpp[temp]++;
        }
        
        return mpp.size();
    }
};