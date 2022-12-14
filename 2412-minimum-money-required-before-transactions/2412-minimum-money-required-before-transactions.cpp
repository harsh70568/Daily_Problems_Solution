class Solution {
public:
    static bool cmp(vector<int>&A, vector<int>&B)
{
    int opt1 = min(-A[0], -A[0] + A[1] -B[0]) ;
    int opt2 = min(-B[0], -B[0]+B[1]-A[0]) ;
    
    if(opt1 < opt2) return true ;
    if(opt1 > opt2) return false ;
    
    return A[0] > B[0] ;
}
    bool is_possible(vector<vector<int>> &trans, long long mid)
    {
        long long total = 0;
        for(int i = 0; i < trans.size(); i++)
        {
            if(mid < trans[i][0]) return false;
            mid = mid + trans[i][1] - trans[i][0];
        }
        
        return true;
    }
    long long minimumMoney(vector<vector<int>>& trans) {
        sort(trans. begin(), trans.end(), cmp);
        
        long long sum = 0;;
        for(auto it : trans)
        {
            sum += it[0];
        }
        
        long long low = 0;
        long long high = sum;
        
        long long ans = 0;
        while(low <= high)
        {
            long long mid = (low + high) >> 1;
            
            if(is_possible(trans, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
        
    }
};