class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int result = 0;
        vector<pair<int,int>>v(26,{-1,-1});
        for(int i = 0; i<n; i++){
            int idx = s[i] - 'a';
            if(v[idx].first == -1){
                v[idx].first = i;
            }
            v[idx].second = i;
        }
        for(int i = 0; i<26; i++){
            int left = v[i].first;
            int right = v[i].second;
            if(left == -1) continue;
            unordered_set<char>sub;
            for(int i = left + 1 ; i<right ; i++){
                sub.insert(s[i]);
            }
            result += sub.size();
        }
        return result;
    }
};
