class Solution {
public:

    int check(vector<int>piles , int h, int mid)
    {
         long long int count = 0 ;

        for(int i=0;i<piles.size();i++)
        {
             count += (piles[i] / mid*1LL);
             if(piles[i] % mid != 0) count++;
        }
    
        return count <= h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
         if(n==1)
         {
             return ceil(piles[0]/(h*1.0)) ;
         }
        int l  =  1;
        int r  =  INT_MIN;
        for(int i=0;i<n;i++)
        {
            r = max(r,piles[i]);
        } 
        int ans  = -1;
        while(l<=r)
        {
            int mid  =  (l+r) >> 1 ;

            if(check(piles,h,mid))
            {
                ans = mid;
                r = mid-1;  
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
    }
};