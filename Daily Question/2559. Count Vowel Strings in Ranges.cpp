class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int cnt = 0;
        vector<int>W;
        for(int i = 0; i<n; i++){
            string word = words[i];
            int l = word.length();
            if((word[l-1] == 'a' || word[l-1] == 'e' || word[l-1] == 'i' || word[l-1] == 'o' || word[l-1] == 'u')
            && (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')
            ){
                cnt++;
            }
                W.push_back(cnt);
        }
        vector<int>ans;
        for(int i = 0; i<queries.size(); i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(a == 0) ans.push_back(W[b]);
            else ans.push_back(W[b] - W[a-1]);
        }
        return ans;
    }
};
