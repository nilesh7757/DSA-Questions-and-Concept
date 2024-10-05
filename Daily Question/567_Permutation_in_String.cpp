class Solution {
    bool isPermutation(string s1,string s2){
        if(s1 == s2) return true;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1 == s2) return true;
        return false;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        for(int i = 0; i<m-n+1; ++i){
            if(isPermutation(s1,s2.substr(i,n))) return true;
        }
        return false;
    }
};
