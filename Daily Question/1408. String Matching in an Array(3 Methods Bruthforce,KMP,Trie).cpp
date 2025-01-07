class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string>result;
        unordered_set<string>r;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(i == j) continue;
                if(words[j].find(words[i]) != string::npos){
                    r.insert(words[i]);
                }
            }
        }
        for(string s:r){
            result.push_back(s);
        }
        return result;
    }
};
