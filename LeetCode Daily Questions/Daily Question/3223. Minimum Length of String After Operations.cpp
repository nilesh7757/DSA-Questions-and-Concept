class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(n<3) return n;
        vector<int>v(26,0);
        for(int i = 0; i<n; i++){
            v[s[i] - 'a']++;
        }
        int cnt = 0;
        for(int i = 0; i<26; i++){
            if(v[i] >= 3){
                if(v[i]%2 == 1){
                    v[i] = 1;
                }
                else{
                    v[i] = 2;
                }
            }
            cnt += v[i];
        }
        return cnt;
    }
};
