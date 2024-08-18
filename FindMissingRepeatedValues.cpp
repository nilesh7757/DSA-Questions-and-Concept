class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long S1 = 0,S2 = 0;
        int k = grid.size();
        int m = grid[0].size();
        long long n = k*m;
        long long S1N = (n* (n+1))/2;
        long long S2N = (n*(n+1)*(2*n+1))/6;
        for(int i = 0; i<k;i++){
            for(int j = 0; j<m; j++){
                S1 += grid[i][j];
                S2 += (long long)grid[i][j] * (long long)grid[i][j];
            }
        }
        long long val1 = S1-S1N;
        long long val2 = S2-S2N;
        val2 = val2/val1;
        long long x = (val1 + val2)/2;
        long long y = x - val1;
        return {(int)x,(int)y};
    }
};
