class Solution {
public:
    int maxProduct(vector<int>& a) {
        int ans = INT_MIN,prefix =1,suffix = 1;
        int n = a.size();
	for(int i=0;i<a.size();i++){
		prefix*=a[i];
		suffix*=a[n-1-i];
		ans = max(ans,max(prefix,suffix));
		if(prefix==0)prefix=1;
		if(suffix==0)suffix=1;
}
return ans;

    }
};