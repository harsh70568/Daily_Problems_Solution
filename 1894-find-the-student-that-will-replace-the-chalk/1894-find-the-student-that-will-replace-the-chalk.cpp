#define ll long long
class Solution {
public:
    int chalkReplacer(vector<int>& c, int k) {
        ll sum = accumulate(c.begin(), c.end(), 0LL);
        ll ans = k % sum;
        vector<ll> p(c.size());
        p[0] = c[0];
        for(ll i = 1; i < c.size(); i++)
        {
            p[i] = p[i-1] + c[i];
        }
        //cout<<ans<<endl;
        return upper_bound(p.begin(), p.end(), ans) - p.begin();
    }
};