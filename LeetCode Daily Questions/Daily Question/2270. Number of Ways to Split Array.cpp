class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long n = nums.size();
        vector<long long>ans(nums.begin(),nums.end());
        for(int i = 1; i<n; i++){
            ans[i] = ans[i] + ans[i-1];
        }
        long long sum = ans[n-1];
        int cnt = 0;
        for(int i = 0; i<n-1; i++){
            if(ans[i] >= sum - ans[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
