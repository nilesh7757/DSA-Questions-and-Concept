class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = arr.size();
        int a = mat.size();
        int b = mat[0].size();
        unordered_map<int,int> mp;
        for(int i = 0; i<n; i++){
            mp[arr[i]] = i;
        }
        vector<int>row(a,-1);
        vector<int>col(b,-1);
        for(int i = 0; i<a; i++){
            for(int j = 0; j<b;j++){
                int index = mp[mat[i][j]];
                row[i] = max(row[i],index);
                col[j] = max(col[j],index);
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i<a; i++){
            mini = min(row[i],mini);
        }
        for(int i = 0; i<b; i++){
            mini = min(col[i],mini);
        }
       return mini;
    }
};
