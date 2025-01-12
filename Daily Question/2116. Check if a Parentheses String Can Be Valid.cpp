class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n%2 == 1) return false;
        int cntC = 0;
        int cntD = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '(' || locked[i] == '0'){
                cntC++;
            }
            else{
                cntC--;
            }
            if(cntC < 0){
                return false;
            }
        }

        for(int i = n-1;i>=0; i--){
            if(s[i] == ')' || locked[i] == '0'){
                cntD++;
            }
            else{
                cntD--;
            }
            if(cntD< 0){
                return false;
            }
        }
        return true;
    }
};
