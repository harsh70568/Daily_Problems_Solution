class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> mpp;
        int maxi = INT_MIN;
        string ans = "";
        
        for(int i = 0; i < messages.size(); i++)
        {
            int count = 1;
            string temp = "";
            for(int j = 0; j < messages[i].length(); j++)
            {
                if(messages[i][j] == ' ')
                {
                    count++;
                }
            }
            mpp[senders[i]] += count;
            
        }
        
        for(int i = 0; i < senders.size(); i++)
        {
            if(mpp[senders[i]] >= maxi)
            {
                if(mpp[senders[i]] == maxi)
                {
                    ans = max(ans,senders[i]);
                }
                else
                {
                    ans = senders[i];
                }
                maxi = mpp[senders[i]];
            }
        }
        
        return ans;
    }
};