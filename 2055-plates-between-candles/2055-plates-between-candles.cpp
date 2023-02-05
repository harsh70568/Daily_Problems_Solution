class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n = s.size();
        vector<int> pos;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '|') pos.push_back(i);
        }
        vector<int> ans(q.size(), 0);
        vector<int> prefix(n);
        prefix[0] = (s[0] == '*' ? 1 : 0);
        for(int i = 1; i < n; i++)
        {
            if(s[i] == '*') prefix[i] = prefix[i-1] + 1;
            else prefix[i] = prefix[i-1];
        }
        if(pos.size() == 0) return ans;
        for(int i = 0; i < q.size(); i++)
        {
            int l = q[i][0];
            int r = q[i][1];

            auto it = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);
            // it2--;
            // int ri = *it2;
            //cout<<li<<" "<<ri<<endl;
            if(it == pos.end() || it2 == pos.begin()) ans[i] = 0;
            else if(*it == 0) ans[i] = prefix[*(--it2)];
            else ans[i] = (max(0,prefix[*(--it2)] - prefix[*it-1]));
            
        }
        
        return ans;
                     
    }
};