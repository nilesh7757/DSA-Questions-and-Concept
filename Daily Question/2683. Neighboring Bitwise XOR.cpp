class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = ans ^ derived[i];
        }
        return ans == 0;
    }
};
