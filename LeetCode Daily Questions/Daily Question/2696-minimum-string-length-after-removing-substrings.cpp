class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        int n = s.length();
        st.push(s[0]);
        for(int i = 1; i<n; i++){
            if((!st.empty()) && ((s[i] == 'B' && st.top() == 'A') || (s[i] == 'D' && st.top() == 'C'))){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.size() == 0) return 0;
        return st.size();

    }
};
