class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string s="";
        while(n>0){
            if(n%2) s+='1';
            else s+='0';
            n/=2;
        }
        for(int i=s.size();i<=32;i++){
            s+='0';
        }
        uint32_t ans=0;
        int x=0;
        
        for(int i=31;i>=0;i--){
            if(s[i]=='1') ans += pow(2,x);
            x++;
        }
        return ans;
    }
};