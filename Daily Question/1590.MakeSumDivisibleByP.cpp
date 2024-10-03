class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int currSum = 0;
        for(int &x : nums){
               currSum = (currSum+x)%p;

        }
        int target = currSum%p;
        if(target == 0) return 0;
        unordered_map<int,int>mp;
        int curr = 0;
        int result = n;
        mp[0] = -1;
        for(int i = 0; i<n; i++){
            curr = (curr + nums[i])%p;
            int remain = (curr-target+p)%p;
            if(mp.find(remain) != mp.end()){
                result = min(result,i-mp[remain]);
            }
            mp[curr] = i;
        }
        if(result == n) return -1;
        return result;
    }
};
