class Solution {
    void swap(int &a,int &b){
        int t = a;
        a = b;
        b = t;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
