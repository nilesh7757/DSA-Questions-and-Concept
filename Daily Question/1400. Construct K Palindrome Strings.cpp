class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>cnt(26,0);
        int n = s.length();
        if(k > n) return false;
        if(k == n) return true;
        for(int i = 0; i<n; i++){
            cnt[s[i] - 'a']++;
        }
        int cntOne = 0;
        for(int i = 0; i<26;i++){
            if(cnt[i]%2 == 1){
                cntOne++;
            }
        }
        if(cntOne <= k) return true;
        return false;
    }
};
