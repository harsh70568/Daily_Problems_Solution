class Solution {
public:
    int find_freq(string s)
    {
        char c = 'z';
        unordered_map<char,int> mpp;
        for(auto it : s)
        {
            mpp[it]++;
            c = min(c,it);
        }
        return mpp[c];
        
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = queries.size();
        int m = words.size();
        
        vector<int> temp1(n);
        vector<int> temp2(m);
        vector<int> ans(n,0);
        
        for(int i = 0; i < n; i++)
        {
            temp1[i] = find_freq(queries[i]);
        }
        
        for(int i = 0; i < m; i++)
        {
            temp2[i] = find_freq(words[i]);
        }
        
        sort(temp2.begin(),temp2.end());
        
        for(int i = 0; i < n; i++)
        {
           for(int j = 0; j < m; j++)
           {
               if(temp2[j] > temp1[i])
               {
                   ans[i] = m - j;
                   break;
               }
           }
        }
        
        return ans;
        
    }
};