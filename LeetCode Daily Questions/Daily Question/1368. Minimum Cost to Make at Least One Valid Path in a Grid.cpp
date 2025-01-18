class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        priority_queue <vector<int>, vector<vector<int>>, greater<> > pq;
        pq.push({0,0,0});
        result[0][0] = 0;
        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int currCost = curr[0];
            int i1 = curr[1];
            int j1 = curr[2];
            for(int i = 0; i<=3;i++){
                int i2 =i1 + dir[i][0];
                int j2 =j1 + dir[i][1];
                if(i2 >= 0 && j2>=0 && i2<n && j2<m){
                    int gridDir = grid[i1][j1];
                    int dirCost = ((gridDir-1 != i)?1:0);
                    int newCost = currCost + dirCost;
                    if(newCost < result[i2][j2]){
                        result[i2][j2] = newCost;
                        pq.push({newCost,i2,j2});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};
