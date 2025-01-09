class Solution {
    int nCr(int n,int r){
        int ans = 1;
        for(int i = 0; i<r; i++){
            ans = ans*(n-i);
            ans = ans/(i+1);
        }
        return ans;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 1; i<=numRows; i++){
            vector<int>temp;
            for(int j = 1;j<=i;j++){
                temp.push_back(nCr(i-1,j-1));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
