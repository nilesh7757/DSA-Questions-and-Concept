class Solution {
    void swap(int &a,int &b){
        int t = a;
        a = b;
        b = t;
    }

public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size()-1;
        int index = -1;
        int i = n-1;
        while(i>=0){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
            i--;
        }
        if(i == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i = n; i >= index ; i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};
