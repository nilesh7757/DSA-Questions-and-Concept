class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int>count(26,0);
        int n = words1.size();
        int m = words2.size();
        for(int i = 0; i<m; i++){
            vector<int>cnt(26,0);
            for(int j = 0;j<words2[i].size();j++){
                cnt[words2[i][j] - 'a']++;
            }
            for(int j = 0; j<26;j++){
                count[j] = max(count[j],cnt[j]);
            } 
           
        }
        vector<string>ans;
        for(int i = 0; i<n; i++){
            vector<int>cnt2(26,0);
            bool flag = true;
            for(int j = 0;j<words1[i].size();j++){
                cnt2[words1[i][j] - 'a']++;
            }
            for(int j = 0; j<26;j++){
                if(cnt2[j] < count[j]){
                   flag = false;
                   break;
                }
            }
            if(flag) ans.push_back(words1[i]);
            
        }
        return ans;
    }
};
