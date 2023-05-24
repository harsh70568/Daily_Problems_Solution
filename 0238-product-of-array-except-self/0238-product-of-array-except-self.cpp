class Solution {
public:
   vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();

       int pre[n],pos[n];

        pre[0]=nums[0];

        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]*nums[i];
        }

  pos[n-1]=nums[n-1];

 for(int i=n-2;i>=0;i--){
            pos[i]=pos[i+1]*nums[i];
        }
vector<int>ans(n,0);
if(nums[0]!=0){
ans[0]=pos[0]/nums[0];
}
else{
    ans[0]=pos[1];
}

if(nums[n-1]!=0){
ans[n-1]=pre[n-1]/nums[n-1];
}
else{
    ans[n-1]=(pre[n-2]);
}



for(int i=1;i<n-1;i++){

if(nums[i]!=0){
 ans[i]=pre[i]/nums[i]*pos[i]/nums[i];
}

else {
    ans[i]=pre[i-1]*pos[i+1];
}

}

return ans;


    }
};