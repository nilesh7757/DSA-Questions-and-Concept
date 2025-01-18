class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        int n = arr.size();
        vector<int>ans(n);
        for(int i = 0; i<n; i++){
            mp[arr[i]] = i;
        }
        int i = 1;
        for(auto &it: mp){
            it.second = i;
            i++;
        }
        for(int i = 0; i<n; i++){
            ans[i] = mp[arr[i]];
        }
        
        return ans;
    }
};
