class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int index = 1;
        
        while(top <= bottom && left <= right)
        {
            for(int i = left; i <= right; i++)
            {
                ans[top][i] = index;
                index++;
            }
            top++;
            
            for(int i = top; i <= bottom; i++)
            {
                ans[i][right] = index;
                index++;
            }
            right--;
            
            for(int i = right; i >= left; i--)
            {
                ans[bottom][i] = index;
                index++;
            }
            bottom--;
            
            for(int i = bottom; i >= top; i--)
            {
                ans[i][left] = index;
                index++;
            }
            left++;
        }
        return ans;
    }
};