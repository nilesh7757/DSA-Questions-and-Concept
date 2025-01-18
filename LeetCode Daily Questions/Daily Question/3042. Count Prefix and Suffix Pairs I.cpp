class Solution {
    bool hasSuffix(string str,string suffix) {
        if (suffix.length() > str.length())
            return false;
        return str.substr(str.length() - suffix.length()) == suffix;
    }
    bool hasPrefix(string str,string prefix) {
        return str.substr(0, prefix.length()) == prefix;
    }

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i == j)
                    continue;
                if(hasPrefix(words[j],words[i]) && hasSuffix(words[j],words[i])){
                    cnt++;
                }
                
            }
        }
        return cnt;
    }
};
