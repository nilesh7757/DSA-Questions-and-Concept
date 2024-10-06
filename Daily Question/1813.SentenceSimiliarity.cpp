class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length() < s2.length()){
            swap(s1,s2);
        }
        vector<string>v1;
        vector<string>v2;
        stringstream ss1(s1);
        string token;
…            i++;
            k++;
        }
        while(l>=k  && v2[l] == v1[j]){
            l--;
            j--;
        }
        return l<k;
    }
};
