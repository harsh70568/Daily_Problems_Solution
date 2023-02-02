class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mpp;
        for(int i = 0; i < order.length(); i++)
        {
            mpp[order[i]] = i+1;
        }
        
        for(int i = 1; i < words.size(); i++)
        {
            //if(words[i].length() < words[i-1].length()) return false;
            int n1 = words[i].length();
            int n2 = words[i-1].length();
            for(int j = 0; j < max(n1, n2); j++)
            {
                if(mpp[words[i][j]] < mpp[words[i-1][j]])
                {
                    return false;
                }
                else if(mpp[words[i][j]] > mpp[words[i-1][j]])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
        
        return true;
    }
};