class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // vector<int>nums(n*m + 1);
        int ans  = 0;
        if(n%2 != 0){
            for(int i = 0; i<m; i++){
                ans = ans ^ nums2[i];
            }
        }
        if(m%2 != 0){
            for(int j = 0; j<n; j++ ){
                ans = ans ^ nums1[j];
            }
        }
        return ans;
    }
};
